#include "globalarray.h"

GlobalArray::GlobalArray()
{

        mapRToIS[0]="V"; mapRToIS[1]="X"; mapRToIS[2]="Q"; mapRToIS[3]="K";
        mapRToIS[4]="M"; mapRToIS[5]="P";mapRToIS[6]="C";mapRToIS[7]="Y";
        mapRToIS[8]="F";mapRToIS[9]="S";mapRToIS[10]="T";mapRToIS[11]="B";
        mapRToIS[12]="U";mapRToIS[13]="E";mapRToIS[14]="O";mapRToIS[15]="I";
        mapRToIS[16]="R";mapRToIS[17]="Z";mapRToIS[18]="D";mapRToIS[19]="A";

        mapIsToN["A"]=19; mapIsToN["B"]=11; mapIsToN["C"]=6; mapIsToN["D"]=18;
        mapIsToN["E"]=13; mapIsToN["F"]=8; mapIsToN["I"]=15; mapIsToN["K"]=3;
        mapIsToN["M"]=4; mapIsToN["O"]=14; mapIsToN["P"]=5; mapIsToN["Q"]=2;
        mapIsToN["R"]=16; mapIsToN["S"]=9; mapIsToN["T"]=10; mapIsToN["U"]=12;
        mapIsToN["V"]=0; mapIsToN["X"]=1; mapIsToN["Y"]=7; mapIsToN["Z"]=17;

        mapCNToCK=mapRToIS;
    //0
        mapFourMMSI[0]="V"; mapFourMMSI[1]="X";mapFourMMSI[2]="Q";mapFourMMSI[3]="K";
        mapFourMMSI[4]="M"; mapFourMMSI[5]="P";mapFourMMSI[6]="C";mapFourMMSI[7]="Y";
        mapFourMMSI[8]="F"; mapFourMMSI[9]="S";

     //1
         mapFiveMMSIAdd[0]="T";mapFiveMMSIAdd[1]="B";mapFiveMMSIAdd[2]="U";mapFiveMMSIAdd[3]="E";
         mapFiveMMSIAdd[4]="O";mapFiveMMSIAdd[5]="I";mapFiveMMSIAdd[6]="R";mapFiveMMSIAdd[7]="Z";
         mapFiveMMSIAdd[8]="D";mapFiveMMSIAdd[9]="A";

         mapFiveToFour[0]="1000";   mapFiveToFour[1]="0100";  mapFiveToFour[2]="0010";
         mapFiveToFour[3]="0001";   mapFiveToFour[4]="1100";  mapFiveToFour[5]="1010";
         mapFiveToFour[6]="1001";   mapFiveToFour[7]="0110";  mapFiveToFour[8]="0101";
         mapFiveToFour[9]="0011";

         mapLetterToNum["A"]=0x0E;mapLetterToNum["B"]=0x58;mapLetterToNum["C"]=0x23;mapLetterToNum["D"]=0x1A;
         mapLetterToNum["E"]=0x4A;mapLetterToNum["F"]=0x13;mapLetterToNum["G"]=0x29;mapLetterToNum["H"]=0x34;
         mapLetterToNum["I"]=0x26;mapLetterToNum["J"]=0x0B;mapLetterToNum["K"]=0x43;mapLetterToNum["L"]=0x2C;
         mapLetterToNum["M"]=0x31;mapLetterToNum["N"]=0x32;mapLetterToNum["O"]=0x38;mapLetterToNum["P"]=0x25;
         mapLetterToNum["Q"]=0x45;mapLetterToNum["R"]=0x2A;mapLetterToNum["S"]=0x16;mapLetterToNum["T"]=0x68;
         mapLetterToNum["U"]=0x46;mapLetterToNum["V"]=0x61;mapLetterToNum["W"]=0x0D;mapLetterToNum["X"]=0x51;
         mapLetterToNum["Y"]=0x15;mapLetterToNum["Z"]=0x1C;

         mapLetterToNum["a"]=0x0E;mapLetterToNum["b"]=0x58;mapLetterToNum["c"]=0x23;mapLetterToNum["d"]=0x1A;
         mapLetterToNum["e"]=0x4A;mapLetterToNum["f"]=0x13;mapLetterToNum["g"]=0x29;mapLetterToNum["h"]=0x34;
         mapLetterToNum["i"]=0x26;mapLetterToNum["j"]=0x0B;mapLetterToNum["k"]=0x43;mapLetterToNum["l"]=0x2C;
         mapLetterToNum["m"]=0x31;mapLetterToNum["n"]=0x32;mapLetterToNum["o"]=0x38;mapLetterToNum["p"]=0x25;
         mapLetterToNum["q"]=0x45;mapLetterToNum["r"]=0x2A;mapLetterToNum["s"]=0x16;mapLetterToNum["t"]=0x68;
         mapLetterToNum["u"]=0x46;mapLetterToNum["v"]=0x61;mapLetterToNum["w"]=0x0D;mapLetterToNum["x"]=0x51;
         mapLetterToNum["y"]=0x15;mapLetterToNum["z"]=0x1C;

         mapLetterToNum["-"]=0x0E; mapLetterToNum["?"]=0x58; mapLetterToNum[":"]=0x23; mapLetterToNum["$"]=0x1A;
         mapLetterToNum["3"]=0x4A;/**hou mian yu liu 3 ge **/ mapLetterToNum["@"]=0x13;mapLetterToNum["#"]=0x29;mapLetterToNum["%"]=0x34;
         mapLetterToNum["8"]=0x26; mapLetterToNum["&"]=0x0B;mapLetterToNum["("]=0x43;mapLetterToNum[")"]=0x2C;
         mapLetterToNum["."]=0x31; mapLetterToNum[","]=0x32;mapLetterToNum["9"]=0x38;mapLetterToNum["0"]=0x25;
         mapLetterToNum["1"]=0x45;mapLetterToNum["4"]=0x2A;mapLetterToNum["'"]=0x16;mapLetterToNum["5"]=0x68;
         mapLetterToNum["7"]=0x46;mapLetterToNum["="]=0x61;mapLetterToNum["2"]=0x0D;mapLetterToNum["/"]=0x51;
         mapLetterToNum["6"]=0x15;mapLetterToNum["+"]=0x1C;

         mapSwitchLetterAndNum["toLetter"]=0x52;
         mapSwitchLetterAndNum["toNum"]=0x49;
         mapSwitchLetterAndNum[" "]=0x62;
         mapSwitchLetterAndNum["huiChe"]=0x70;
         mapSwitchLetterAndNum["huanHang"]=0x64;

         //mapNumToNum["1"]=0x8A;  mapNumToNum["2"]=0x1A; mapNumToNum["3"]=0x94;
}
