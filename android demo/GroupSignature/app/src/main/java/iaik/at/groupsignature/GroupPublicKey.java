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

public class GroupPublicKey {
    public EcPoint_Fp g1;

    public EcPoint_Fp h;

    public EcPoint_Fp u;

    public EcPoint_Fp v;

    public EcPoint_Fp2 g2;

    public EcPoint_Fp2 w;

    public GroupPublicKey() {
        int[] g1_x = {0x00000085, 0x91000000, 0x00000089, 0xA7E70000, 0x0000003A, 0x176E1E80, 0xC000000C, 0x03F7BF8F};
        int[] g1_y = {0xFFFFFF8E, 0x15FFFFFF, 0xFFFFFF8A, 0xB939FFFF, 0xFFFFFFCD, 0xA2C62EFF, 0x7FFFFFF5, 0x212BA4F2};
        g1 = new EcPoint_Fp(g1_x, g1_y, (byte)0);
        int[] h_x = {0xb9b90a3e ,0x1ba275af ,0xab62dff1 ,0x35ab737e ,0x97f6c597 ,0x31012e4a ,0xc3bb581f ,0x1b031f27};
        int[] h_y = {0xd09b6f41 ,0xf675556e ,0x3ef69cf7 ,0xb7c77d8d ,0x74f58837 ,0xc943b550 ,0xa2f544fc ,0x095d0206};
        h = new EcPoint_Fp(h_x, h_y, (byte)0);

        int[] u_x ={0x1214f57b ,0x8754e243 ,0xf013ad7c ,0xc45f4914 ,0x918fa0f4 ,0xb6c5f3d5 ,0x900a25b1 ,0x2398c4a8};
        int[] u_y = {0x68959bf9 ,0x070360e8 ,0x056fb1d8 ,0x31453324 ,0xf7d8d84a ,0x0a263f24 ,0x0444c393 ,0x12c267d8};
        u = new EcPoint_Fp(u_x, u_y, (byte)0);

        int[] v_x = {0x39d7df61 ,0x566a2315 ,0xc300bc66 ,0x7e756426 ,0xa603e9cc ,0xd917fc5a ,0x2eb7ebc8 ,0x10946b0b};
        int[] v_y = {0x5c24ca16 ,0x17d181c5 ,0x822ba6db ,0x5443ea21 ,0x2918f68d ,0x460ac018 ,0xf0763730 ,0x087a1150};
        v = new EcPoint_Fp(v_x, v_y, (byte)0);

        int[][] g2_x = {{0x63659E66, 0xAF45AAAF, 0x3D01BC7C,
                0xBB92F023, 0xDCD46337, 0xEF7AB941, 0x61DF5B55, 0x173F71DE},
                {0xD0D2F4E7, 0x389BBB43, 0xBC087B6A, 0x413D1E26, 0x7A42E357, 0x1FCE9382,
                        0x6630C4E9, 0x10C76BD0}};
        int[][] g2_y = {{0x74482015, 0x25D0B136, 0x0C7D1012, 0x5A0FCF13, 0x884B2CC7,
                0x9215E25E, 0x1C2D120D, 0x182C7A58},
                {0xFCB5D7AA, 0xFBB0D5E1, 0xA3A25124, 0x6CE6262A, 0x927F8598, 0x1E0D27E0,
                        0x781D1A20, 0x1598CFFE}};
        g2 = new EcPoint_Fp2(g2_x, g2_y, (byte)0);


        int[][] w_x = {{0xbe96df53 ,0x64c82d78 ,0xfc1faada ,0x432734fe ,0xa1a5f284 ,0xb83612d7 ,0xc86466c4 ,0x15712e4f},
                {0x8d5b069f ,0x8c81e6ae ,0x0a9caaa9 ,0xad6c4066 ,0x500700f5 ,0xce71a7b0 ,0xad4ac8e7 ,0x093427ee}};
        int[][] w_y = {{0xa71d7d31 ,0xceebfea0 ,0x48b98721 ,0x3aa09a82 ,0x861d3355 ,0xce8adb8a ,0xe69b163c ,0x11d4fa8f},
                {0xbf0c14af ,0xa1a7e060 ,0x154026c3 ,0x1ebb3523 ,0xe55d0f21 ,0x7edf9eb3 ,0x8c3ee4d6 ,0x0391a0f7}};
        w = new EcPoint_Fp2(w_x, w_y, (byte)0);

    }
}
