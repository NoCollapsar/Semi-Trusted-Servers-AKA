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

packet VMessage extends BaseFrame1609_4 {
    int Dvi;        // 车辆ID
    int Cvi1;           
    int Cvi2;         
    int Cvi3;   
    simtime_t T1;      // 时间戳 T1
}

packet RMessage extends BaseFrame1609_4 {
    int TVNi;  
    int IDRi;     // RSU ID
    int CRi1;           
    int Rvi;   
    simtime_t T2;      // 时间戳 T2
}
   
packet RBroad extends BaseFrame1609_4 {
    int IDRi;       // RSU ID
    int XRi;
    int CRi;
    int ARi;
   
   
}
   
