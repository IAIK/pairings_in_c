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

import android.app.Activity;
import android.app.PendingIntent;
import android.content.Intent;
import android.content.IntentFilter;
import android.nfc.NdefMessage;
import android.nfc.NdefRecord;
import android.nfc.NfcAdapter;
import android.nfc.Tag;
import android.os.Bundle;
import android.os.Parcelable;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import java.nio.ByteBuffer;
import java.nio.charset.Charset;
import java.security.Signature;

public class NFCReaderActivity extends Activity {
    // used constants for NFC-communication
    public static final String MIME_IAIK_MESSAGE = "at/iaik/groupsignature";
    public static final String MIME_IAIK_DATA = "at/iaik/groupsignature/Data";
    public static final String TAG = "NfcDemo";

    // layout elements
    public TextView mTextView;
    private Button openButton;
    private TextView mTextViewGroupMaster;

    // adapter for NFC-communication
    private NfcAdapter mNfcAdapter;

    // the group scheme of the incoming message
    private SdhSignature sig;

    // the used public key of the group scheme
    private GroupPublicKey gpk = new GroupPublicKey();

    // the used master secret key of the group scheme
    private GroupMasterSecretKey gmsk = new GroupMasterSecretKey();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        mNfcAdapter = NfcAdapter.getDefaultAdapter(this);
        // set the right layout
        setContentView(R.layout.verifier_layout);
        mTextView = (TextView) findViewById(R.id.textVerifier);
        mTextViewGroupMaster = (TextView) findViewById(R.id.textGroupMaster);
        openButton = (Button) findViewById(R.id.buttonOpen);
        openButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // if signature is valid, button is enabled
                // open the signature
                EcPoint_Fp A = MainActivity.open(gmsk, sig);
                mTextViewGroupMaster.setText(getString(R.string.sig_from_user) + " " + getGskPosition(A));
            }
        });

        if (!mNfcAdapter.isEnabled()) {
            mTextView.setText(getString(R.string.nfc_disabled));
        } else {
            mTextView.setText(getString(R.string.nfc_enabled));
        }

        handleIntent(getIntent());
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

    @Override
    protected void onResume() {
        super.onResume();

        /**
         * It's important, that the activity is in the foreground (resumed). Otherwise
         * an IllegalStateException is thrown.
         */
        setupForegroundDispatch(this, mNfcAdapter);

    }

    @Override
    protected void onPause() {
        super.onPause();
        /**
         * Call this before onPause, otherwise an IllegalArgumentException is thrown as well.
         */
        stopForegroundDispatch(this, mNfcAdapter);
    }

    @Override
    protected void onNewIntent(Intent intent) {
        handleIntent(intent);
    }

    /**
     * This method gets called, when a new Intent gets associated with the current activity instance.
     * Instead of creating a new activity, onNewIntent will be called. For more information have a look
     * at the documentation.
     *
     * In our case this method gets called, when the user attaches a Tag to the device.
     */
    private void handleIntent(Intent intent) {
        String action = intent.getAction();
        // check if the action is NDEF
        if (NfcAdapter.ACTION_NDEF_DISCOVERED.equals(action)) {
            // check if NDEF has the right MIME
            String type = intent.getType();
            if (MIME_IAIK_MESSAGE.equals(type)) {
                // read the Ndef message
                Tag tag = intent.getParcelableExtra(NfcAdapter.EXTRA_TAG);
                Parcelable[] message = intent.getParcelableArrayExtra(NfcAdapter.EXTRA_NDEF_MESSAGES);
                NdefMessage ndefMessage = (NdefMessage) message[0];

                // get records and process them
                NdefRecord[] records = ndefMessage.getRecords();

                byte[] payload = records[0].getPayload();
                String strMessage = new String(payload, 0, payload.length, Charset.forName("UTF-8"));

                byte[] data = records[1].getPayload();
                sig = generateSignature(data);

                int verify = MainActivity.verify(strMessage, gpk, sig);

                // Signature valid or not?
                if(verify == 0) {
                    mTextView.setText(getString(R.string.message) + " " + strMessage + "\n" + getString(R.string.sig_valid));
                    openButton.setClickable(true);
                    openButton.setEnabled(true);
                    mTextViewGroupMaster.setText("");
                } else {
                    mTextView.setText(getString(R.string.message) + " " + strMessage + "\n" + getString(R.string.sig_invalid));
                    openButton.setClickable(false);
                    openButton.setEnabled(false);
                    mTextViewGroupMaster.setText("");
                }

            } else {
                Log.d(TAG, "Wrong mime type: " + type);
            }
        }
    }

    /**
     * Simple method for determining the position of the used gsk.
     * Values are hardcoded (only demo app)
     *
     * @param A The elliptic curve point of the used group secret key
     * @return pos of the used key
     */
    private int getGskPosition(EcPoint_Fp A) {
        int[][] A_x_all = {{0x7e9db9e6 ,0x4948d7ba ,0x3a90d5ab ,0xe8ebc5e5 ,0x381d3b8a ,0x32b61247 ,0x20c10a0e ,0x03f2b493},
                {0x086bac37 ,0x3c9f4ea5 ,0xda15cb34 ,0xdb438d16 ,0x10905e92 ,0x888491eb ,0xf79f65bb ,0x1ba2c9fa},
                {0x6b226fe9 ,0x656ea8cf ,0x000e3782 ,0xbb159453 ,0x57065892 ,0x31f6f630 ,0x748f7cc4 ,0x06e1a1dc},
                {0x7f13e88c ,0xecbefb70 ,0x768fd003 ,0xdfaebdf1 ,0x3b9a2321 ,0x3ae35f93 ,0xe9ab4b4e ,0x02997b19}};

        int[][] A_y_all = {{0xeced1a4e ,0x4d6319a3 ,0x9c3d2b93 ,0x71a7219b ,0x673fe027 ,0x96f48b93 ,0x3c13396f ,0x13f60481},
                {0x623a6b43 ,0x1e4461c3 ,0xb7646448 ,0xf84ceab0 ,0x534e077d ,0x3b424864 ,0x87289d6d ,0x237119da},
                {0xf64b8752, 0x9e278173 ,0x069eef26 ,0xbc9039de ,0xee48a698 ,0xab897d6a ,0x85ffb4c3 ,0x072e4b4c},
                {0x1c411103 ,0xd969dd05 ,0x8e956746 ,0x7f9726f9 ,0xa79ecf96 ,0x3ca8f4d7 ,0x972e3b81 ,0x1ac18d08}};
        final int number_of_gsks = 4;
        boolean is_equal = false;
        int pos = -2;
        for (int i = 0; (i < number_of_gsks) && (!is_equal); i++) {
            for (int j = 0; j < 8; j++) {
                if(A.x[j] != A_x_all[i][j] || A.y[j] != A_y_all[i][j]) {
                    is_equal = false;
                    break;
                }
                is_equal = true;
            }
            pos = i;
        }
        return pos+1;
    }

    /**
     * @param activity The corresponding {@link Activity} requesting the foreground dispatch.
     * @param adapter  The {@link NfcAdapter} used for the foreground dispatch.
     */
    public static void setupForegroundDispatch(final Activity activity, NfcAdapter adapter) {
        final Intent intent = new Intent(activity.getApplicationContext(), activity.getClass());
        intent.setFlags(Intent.FLAG_ACTIVITY_SINGLE_TOP);

        final PendingIntent pendingIntent = PendingIntent.getActivity(activity.getApplicationContext(), 0, intent, 0);

        IntentFilter[] filters = new IntentFilter[2];
        String[][] techList = new String[][]{};

        // Notice that this is the same filter as in our manifest.
        filters[0] = new IntentFilter();
        filters[0].addAction(NfcAdapter.ACTION_NDEF_DISCOVERED);
        filters[0].addCategory(Intent.CATEGORY_DEFAULT);
        filters[1] = new IntentFilter();
        filters[1].addAction(NfcAdapter.ACTION_NDEF_DISCOVERED);
        filters[1].addCategory(Intent.CATEGORY_DEFAULT);
        try {
            filters[0].addDataType(MIME_IAIK_MESSAGE);
            filters[1].addDataType(MIME_IAIK_DATA);
        } catch (IntentFilter.MalformedMimeTypeException e) {
            throw new RuntimeException("Check your mime type.");
        }
        adapter.enableForegroundDispatch(activity, pendingIntent, filters, techList);
    }

    /**
     * Generates the signature from the the received byte array
     * @param b The byte array that contains the signature
     * @return The signature of the group scheme
     */
    SdhSignature generateSignature(byte b[]) {
        SdhSignature sig = new SdhSignature();
        ByteBuffer buff = ByteBuffer.wrap(b);

        for(int i = 0; i < sig.c.length; ++i) {
            sig.c[i] = buff.getInt();
        }

        for(int i = 0; i < sig.s_alpha.length; ++i) {
            sig.s_alpha[i] = buff.getInt();
        }
        for(int i = 0; i < sig.s_beta.length; ++i) {
            sig.s_beta[i] = buff.getInt();
        }
        for(int i = 0; i < sig.s_x.length; ++i) {
            sig.s_x[i] = buff.getInt();
        }
        for(int i = 0; i < sig.s_delta1.length; ++i) {
            sig.s_delta1[i] = buff.getInt();
        }
        for(int i = 0; i < sig.s_delta2.length; ++i) {
            sig.s_delta2[i] = buff.getInt();
        }
        for(int i = 0; i < sig.T_1.x.length; ++i) {
            sig.T_1.x[i] = buff.getInt();
        }
        for(int i = 0; i < sig.T_1.y.length; ++i) {
            sig.T_1.y[i] = buff.getInt();
        }
        for(int i = 0; i < sig.T_2.x.length; ++i) {
            sig.T_2.x[i] = buff.getInt();
        }
        for(int i = 0; i < sig.T_2.y.length; ++i) {
            sig.T_2.y[i] = buff.getInt();
        }
        for(int i = 0; i < sig.T_3.x.length; ++i) {
            sig.T_3.x[i] = buff.getInt();
        }
        for(int i = 0; i < sig.T_3.y.length; ++i) {
            sig.T_3.y[i] = buff.getInt();
        }
        return sig;
    }

    /**
     * @param activity The corresponding {@link BaseActivity} requesting to stop the foreground dispatch.
     * @param adapter  The {@link NfcAdapter} used for the foreground dispatch.
     */
    public static void stopForegroundDispatch(final Activity activity, NfcAdapter adapter) {
        adapter.disableForegroundDispatch(activity);
    }
}
