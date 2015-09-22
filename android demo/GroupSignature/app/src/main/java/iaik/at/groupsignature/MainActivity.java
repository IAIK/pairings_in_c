/****************************************************************************
 **
 ** Copyright (C) 2015 Stiftung Secure Information and
 **                    Communication Technologies SIC and
 **                    Graz University of Technology
 ** Contact: http://opensource.iaik.tugraz.at
 **
 **
 ** Commercial License Usage
 ** Licensees holding valid commercial licenses may use this file in
 ** accordance with the commercial license agreement provided with the
 ** Software or, alternatively, in accordance with the terms contained in
 ** a written agreement between you and SIC. For further information
 ** contact us at http://opensource.iaik.tugraz.at.
 **
 ** GNU General Public License Usage
 ** Alternatively, this file may be used under the terms of the GNU
 ** General Public License version 3.0 as published by the Free Software
 ** Foundation and appearing in the file LICENSE.GPL included in the
 ** packaging of this file.  Please review the following information to
 ** ensure the GNU General Public License version 3.0 requirements will be
 ** met: http://www.gnu.org/copyleft/gpl.html.
 **
 ** This software is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this software. If not, see http://www.gnu.org/licenses/.
 **
 **
 ****************************************************************************/
package iaik.at.groupsignature;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.nfc.NdefMessage;
import android.nfc.NdefRecord;
import android.nfc.NfcAdapter;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.Toast;

import java.nio.ByteBuffer;
import java.nio.charset.Charset;
import java.util.Random;

public class MainActivity extends AppCompatActivity {

    // used constants for NFC-communication
    public static final String MIME_IAIK_MESSAGE = "at/iaik/groupsignature";
    public static final String MIME_IAIK_DATA = "at/iaik/groupsignature/Data";
    public static final String TAG = "NfcDemo";

    // adapter for NFC-communication
    private NfcAdapter mNfcAdapter;

    // layout elements
    private Button sendButton;
    private EditText messageTextField;
    private Spinner spinner;

    // boolean to determine if spinner item was selected
    private boolean isWrongMessage = false;

    // the used public key of the group scheme
    GroupPublicKey gpk =  new GroupPublicKey();

    // the different valid secret keys
    GroupSecretKey[] gsks;

    // the actual used secret key
    GroupSecretKey actualGsk;

    // load the library for the native methods
    static {
        System.loadLibrary("ndkLib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        chooseFunction();
        gsks = generateGsks();
        actualGsk = gsks[0];
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }

    /**
     * Opens the dialog for choosing verifier or signer
     */
    private void chooseFunction() {
        // Dialog for choosing verifier or signer
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setTitle(R.string.choose_function);
        builder.setSingleChoiceItems(R.array.items, 0, null);
        builder.setPositiveButton(R.string.select, new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                int selectedPos = ((AlertDialog) dialog).getListView().getCheckedItemPosition();
                mNfcAdapter = NfcAdapter.getDefaultAdapter(((AlertDialog) dialog).getContext());
                if (mNfcAdapter == null) {
                    // Stop here, we definitely need NFC
                    Toast.makeText(((AlertDialog) dialog).getContext(), getString(R.string.not_supporting_NFC), Toast.LENGTH_LONG).show();
                    finish();
                    return;
                }
                if (selectedPos == 0) {
                    Intent i = new Intent(((AlertDialog) dialog).getContext(), NFCReaderActivity.class);
                    finish();
                    startActivity(i);
                    return;
                } else {
                    setContentView(R.layout.sign_layout);
                    sendButton = (Button) findViewById(R.id.sendButton);
                    messageTextField = (EditText) findViewById(R.id.messageText);
                    if (!mNfcAdapter.isEnabled()) {
                        messageTextField.setText(getString(R.string.nfc_disabled));
                        messageTextField.setEnabled(false);
                        sendButton.setEnabled(false);
                    } else {
                        messageTextField.setText(getString(R.string.nfc_enabled));
                    }

                    // set Elements of spinner
                    spinner = (Spinner) findViewById(R.id.spinner);
                    ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(((AlertDialog) dialog).getContext(), R.array.options, android.R.layout.simple_spinner_item);
                    adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
                    spinner.setAdapter(adapter);
                    // define the action if an item is selected
                    spinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
                        @Override
                        public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                            isWrongMessage = false;
                            if(position < 4) {
                                actualGsk = gsks[position];
                            } else if(position == 4) {
                                actualGsk = new GroupSecretKey(generateRandomIntArray(8), generateRandomIntArray(8), generateRandomIntArray(8));
                            } else {
                                isWrongMessage = true;
                            }
                        }
                        @Override
                        public void onNothingSelected(AdapterView<?> parent) {

                        }
                    });
                    sendButton.setOnClickListener(new View.OnClickListener() {
                        @Override
                        public void onClick(View v) {
                            String message = messageTextField.getText().toString();
                            if (message.trim().isEmpty()) {
                                Toast.makeText(v.getContext(), R.string.no_message, Toast.LENGTH_LONG).show();
                            } else {
                                double t = System.nanoTime();
                                SdhSignature sig = sign(message, gpk, actualGsk);
                                t = System.nanoTime() - t;
                                Log.i("TIME in java",""+t/1000000000.0);
                                if(isWrongMessage) {
                                    message = message + " some text";
                                }
                                // API 10 compatibility
                                mNfcAdapter.enableForegroundNdefPush(MainActivity.this, generateNDefMessage(message, sig));
                            }
                        }
                    });
                }
            }
        }).setNegativeButton(R.string.cancel, new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                System.exit(0);
            }
        });
        AlertDialog dialog = builder.create();
        dialog.show();
    }

    /**
     * Generates a valid Ndef message
     *
     * @param message The message from the user
     * @param sig The signature of the group scheme
     * @return The Ndef message to send via NFC
     */
     private NdefMessage generateNDefMessage(String message, SdhSignature sig) {
        NdefRecord mimeRecordMessage = new NdefRecord(NdefRecord.TNF_MIME_MEDIA, MIME_IAIK_MESSAGE.getBytes(Charset.forName("UTF-8")), new byte[0], message.getBytes(Charset.forName("UTF-8")));
        ByteBuffer b = generateByteSig(sig);
        NdefRecord mimeRecordData = new NdefRecord(NdefRecord.TNF_MIME_MEDIA, MIME_IAIK_DATA.getBytes(Charset.forName("UTF-8")), new byte[0], b.array());

        NdefRecord mimeRecordSend[] =  new NdefRecord[2];
        mimeRecordSend[0] = mimeRecordMessage;
        mimeRecordSend[1] = mimeRecordData;
        NdefMessage ndefMessage = new NdefMessage(mimeRecordSend);
        return ndefMessage;
    }

    /**
     * Generate a byte array from the signature to transfer it via NFC
     *
     * @param sig The signature of the group scheme
     * @return A byte array from the signature
     */
    private ByteBuffer generateByteSig(SdhSignature sig) {
        /**
         * hardcoded size and many for-loops because of demo app
         */
        ByteBuffer b = ByteBuffer.allocate(12*8*4);
        for(int i = 0; i < sig.c.length; ++i) {
            b.putInt(sig.c[i]);
        }
        for(int i = 0; i < sig.s_alpha.length; ++i) {
            b.putInt(sig.s_alpha[i]);
        }
        for(int i = 0; i < sig.s_beta.length; ++i) {
            b.putInt(sig.s_beta[i]);
        }
        for(int i = 0; i < sig.s_x.length; ++i) {
            b.putInt(sig.s_x[i]);
        }
        for(int i = 0; i < sig.s_delta1.length; ++i) {
            b.putInt(sig.s_delta1[i]);
        }
        for(int i = 0; i < sig.s_delta2.length; ++i) {
            b.putInt(sig.s_delta2[i]);
        }
        for(int i = 0; i < sig.T_1.x.length; ++i) {
            b.putInt(sig.T_1.x[i]);
        }
        for(int i = 0; i < sig.T_1.y.length; ++i) {
            b.putInt(sig.T_1.y[i]);
        }
        for(int i = 0; i < sig.T_2.x.length; ++i) {
            b.putInt(sig.T_2.x[i]);
        }
        for(int i = 0; i < sig.T_2.y.length; ++i) {
            b.putInt(sig.T_2.y[i]);
        }
        for(int i = 0; i < sig.T_3.x.length; ++i) {
            b.putInt(sig.T_3.x[i]);
        }
        for(int i = 0; i < sig.T_3.y.length; ++i) {
            b.putInt(sig.T_3.y[i]);
        }
        return b;
    }

    /**
     * Generates an array of random Integers
     *
     * @param size the length of the output int array
     * @return random int array of given size
     */
    private int[] generateRandomIntArray(int size) {
        int[] result = new int[size];
        Random r =  new Random();
        for (int i = 0; i < size; i++) {
            result[i] = r.nextInt();
        }
        return result;
    }

    /**
     * Generates an array of secret key out of hardcoded values (only demo app)
     *
     * @return array of secret keys
     */
    private GroupSecretKey[] generateGsks(){
        int[][] x_all = {{0x804ac869 ,0x1204797c ,0x6ced7e12 ,0xbc8a5e8b ,0x8693c3d3 ,0xa63c68ae ,0x93668dcb ,0x04a086ba},
                {0xda636964 ,0xd691f340 ,0x3ddbdf59 ,0x63f1fb9d ,0x362124f4 ,0xc7732a3b ,0x07bddee3 ,0x1b1cd79e},
                {0x16c13222 ,0xc54730fe ,0x2521226c ,0xc6119dc6 ,0x561fd355, 0x3af41d75 ,0x15bde049, 0x0d1ce030},
                {0xbf53373d ,0x88587b75 ,0x8b6c7dbb ,0x4c8202ff ,0xc3c0aa58 ,0xaa86e4e3 ,0x77d2817f ,0x16def47a}};

        int[][] A_x_all = {{0x7e9db9e6 ,0x4948d7ba ,0x3a90d5ab ,0xe8ebc5e5 ,0x381d3b8a ,0x32b61247 ,0x20c10a0e ,0x03f2b493},
                {0x086bac37 ,0x3c9f4ea5 ,0xda15cb34 ,0xdb438d16 ,0x10905e92 ,0x888491eb ,0xf79f65bb ,0x1ba2c9fa},
                {0x6b226fe9 ,0x656ea8cf ,0x000e3782 ,0xbb159453 ,0x57065892 ,0x31f6f630 ,0x748f7cc4 ,0x06e1a1dc},
                {0x7f13e88c ,0xecbefb70 ,0x768fd003 ,0xdfaebdf1 ,0x3b9a2321 ,0x3ae35f93 ,0xe9ab4b4e ,0x02997b19}};

        int[][] A_y_all = {{0xeced1a4e ,0x4d6319a3 ,0x9c3d2b93 ,0x71a7219b ,0x673fe027 ,0x96f48b93 ,0x3c13396f ,0x13f60481},
                {0x623a6b43 ,0x1e4461c3 ,0xb7646448 ,0xf84ceab0 ,0x534e077d ,0x3b424864 ,0x87289d6d ,0x237119da},
                {0xf64b8752, 0x9e278173 ,0x069eef26 ,0xbc9039de ,0xee48a698 ,0xab897d6a ,0x85ffb4c3 ,0x072e4b4c},
                {0x1c411103 ,0xd969dd05 ,0x8e956746 ,0x7f9726f9 ,0xa79ecf96 ,0x3ca8f4d7 ,0x972e3b81 ,0x1ac18d08}};
        final int number_of_gsks = 4;
        GroupSecretKey[] gsks = new GroupSecretKey[number_of_gsks];
        for (int i = 0; i < number_of_gsks; i++) {
            gsks[i] = new GroupSecretKey(x_all[i], A_x_all[i], A_y_all[i]);
        }
        return gsks;
    }

    /**
     * The native method for signing message from the user.
     *
     * @param message The message from the user
     * @param groupPublicKey The public key of the group scheme
     * @param groupSecretKey The secret key of a signer
     * @return The signature of the group scheme
     */
    public native SdhSignature sign(String message, GroupPublicKey groupPublicKey, GroupSecretKey groupSecretKey);

    /**
     * The native method to verify if the signature of the given message is valid.
     *
     * @param message The message from the user
     * @param groupPublicKey The used public key of the group scheme
     * @param sig The signature of the message
     * @return 0 if signature is valid, -1 if signature is invalid
     */
    public static native int verify(String message, GroupPublicKey groupPublicKey, SdhSignature sig);

    /**
     * The native method trace a signature to the signer.
     *
     * @param groupMasterSecretKey The secret key only the master knows
     * @param sig The signature of the message
     * @return The elliptic curve point corresponds to the signer
     */
    public static native EcPoint_Fp open(GroupMasterSecretKey groupMasterSecretKey, SdhSignature sig);
}



