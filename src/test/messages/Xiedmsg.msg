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

packet XiedVmsg extends BaseFrame1609_4 {
    int SHIDTE;        // 车辆ID
    int M1;          
    int M2;         
    int AUTE;   
    simtime_t T1;      // 时间戳 T1
}

packet XiedRMsg extends BaseFrame1609_4 {
    int M6; 
    int IDCS;     
    int AUS;          
    simtime_t T3;      // 时间戳 T3
}
   
packet XiedIDBroad extends BaseFrame1609_4 {
    int R;       // RSU ID
    string Name="IDBroadcast";
   
}