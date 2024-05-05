#include <bits/stdc++.h>
using namespace std;

int getRandomNumber(){
    return rand()%1000+1;
}
void clearfile(string filename){
    ofstream ofs;
    ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
    if(ofs.is_open())
        ofs.close();
}
int main(){
    srand(time(NULL));
    int times = 100;
    // clearfile("test.txt");
    fstream file;
    file.open("test.txt", ios_base::out);
    if(file.is_open()){
        for(int i = 0; i < times; ++i){
            int n = rand()%50 +1;
            vector<int> days(n);
            generate(days.begin(), days.end(), getRandomNumber);
            file << n << endl;
            int d = days.size()-1;
            int it = 0;
            for_each(days.begin(), days.end(),
                [&file,&it,&d](const auto& elem){
                    file << elem;
                    if(it != d){
                        file << " ";
                    }
                    it++;
                }
            );
            if(i != times-1){
                file << endl;
            }
        }
        file.close();
    }

}