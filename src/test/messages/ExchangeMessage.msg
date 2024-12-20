//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//
import veins.base.utils.Coord;
import veins.modules.messages.BaseFrame1609_4;
import veins.base.utils.SimpleAddress;

namespace veins;

packet M1Message extends BaseFrame1609_4 {
    int VID;        // 车辆ID
    int ri;           // 随机数 r_i
    int W1;         // W1 值
    int W2;   
    int sd;      // W2 值
    simtime_t T1;      // 时间戳 T1
}

packet M2Message extends BaseFrame1609_4 {
    int RID;       // RSU ID
    int rj;           // 随机数 r_j
    int W3;   
    int sd;      // W3 值
    simtime_t T2;      // 时间戳 T2
}
   
packet IDBroad extends BaseFrame1609_4 {
    int R;       // RSU ID
    string Name="IDBroadcast";
   
}
   
