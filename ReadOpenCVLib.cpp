#include<iostream>
#include<fstream>
#include<io.h>
using namespace std;

bool ends_with_lib(char* str){
    int sLen = strlen(str);
    char *libstr = ".lib";
    int libstrLen = strlen(libstr);
    if(libstrLen >= sLen){
        return false;
    }
   
    for(int i=sLen-1,j=libstrLen-1;j>=0;j--,i--){
        if(libstr[j] != str[i])
            return false;
    }
    //cout << "file:\t" << str << endl;
    return true;
}

int main(int argc,char *argv[]){

    cout << "input command line number:"<<argc << endl;
    

    if(argc >= 3){

        cout << "target filename:\t" << argv[1] << endl;
        
        
        long hFile = 0;
        struct _finddata_t fileinfo;
        string p;
        ofstream out;
        out.open(argv[1],ios::in|ios::out|ios::binary|ios::trunc); 
        if(out.is_open()){       
        
    
          for(int i=2;i<argc;i++)
          {
            cout << "lib path:\t" << argv[2] << endl;
            if((hFile = _findfirst(p.assign(argv[i]).append("\\*").c_str(),&fileinfo))!=-1){
                do{
                // if(fileinfo.attrib & _A_SUBDIR){

                //     cout << "file:\t" << fileinfo.name << endl;
                // }
                // else{
                    // cout << "file:\t" << fileinfo.name << endl;
                    // cout << "file last char:\t" << fileinfo.name[strlen(fileinfo.name)-1] << endl;
                    // cout << "file length:\t" << strlen(fileinfo.name) << endl;
                    char * fileName = fileinfo.name;
                    if(ends_with_lib(fileName)){
                        cout << "file:\t" << fileName << endl;
                        string format = string("#pragma comment(lib,\"").append(fileName).append("\")");
                        cout << "output format:\t" << format.c_str() << endl;
                        out << format.c_str() << endl;


                    }
                // }
                }while(_findnext(hFile,&fileinfo)==0);
            }
            _findclose(hFile);
          }
        }
        else{
            cout << "file not open" << endl;
        }
        out << flush;
        out.close();
        
    }    

    cout << "Complete!" << endl;


    return 0;
}





