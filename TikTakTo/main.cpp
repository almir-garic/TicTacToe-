#include <iostream>
#include<vector>
#include<string>
#include <stdlib.h>

using namespace std;
//validacija pobjede (pravila okoline)
bool Provjera(vector<vector<string> > &matrica){
    if( matrica[0][0]=="x" && matrica[1][1]=="x" && matrica[2][2]=="x"){
        cout<<"Prvi je pobijedio"<<endl;
        return false;
    }
    else if(matrica[0][2]=="x" && matrica[1][1]=="x" && matrica[2][0]=="x"){
        cout<<"Prvi je pobijedio"<<endl;
        return false;
    }
     else if(matrica[0][0]=="x" && matrica[0][1]=="x" && matrica[0][2]=="x"){
        cout<<"Prvi je pobijedio"<<endl;
        return false;
    }
     else if(matrica[1][0]=="x" && matrica[1][1]=="x" && matrica[1][2]=="x"){
        cout<<"Prvi je pobijedio"<<endl;
        return false;
    }
    else if(matrica[2][0]=="x" && matrica[2][1]=="x" && matrica[2][2]=="x"){
        cout<<"Prvi je pobijedio"<<endl;
        return false;
    }
     else if(matrica[0][2]=="x" && matrica[1][2]=="x" && matrica[2][2]=="x"){
        cout<<"Prvi je pobijedio"<<endl;
        return false;
    }
     else if(matrica[0][1]=="x" && matrica[1][1]=="x" && matrica[2][1]=="x"){
        cout<<"Prvi je pobijedio"<<endl;
        return false;
    }
    else if(matrica[0][0]=="x" && matrica[1][0]=="x" && matrica[2][0]=="x"){
        cout<<"Prvi je pobijedio"<<endl;
        return false;
    }

    //---------------------------------------------------------------------
    else if(matrica[0][0]=="o" && matrica[1][1]=="o" && matrica[2][2]=="o"){
        cout<<"Racunar je pobijedio"<<endl;
        return false;
    }
    else if(matrica[0][2]=="o" && matrica[1][1]=="o" && matrica[2][0]=="o"){
        cout<<"Racunar je pobijedio"<<endl;
        return false;
    }
     else if(matrica[0][0]=="o" && matrica[0][1]=="o" && matrica[0][2]=="o"){
        cout<<"Racunar je pobijedio"<<endl;
        return false;
    }
     else if(matrica[1][0]=="o" && matrica[1][1]=="o" && matrica[1][2]=="o"){
        cout<<"Drugi je pobijedio"<<endl;
        return false;
    }
    else if(matrica[2][0]=="o" && matrica[2][1]=="o" && matrica[2][2]=="o"){
        cout<<"Racunar je pobijedio"<<endl;
        return false;
    }
     else if(matrica[0][2]=="o" && matrica[1][2]=="o" && matrica[2][2]=="o"){
        cout<<"Racunar je pobijedio"<<endl;
        return false;
    }
     else if(matrica[0][1]=="o" && matrica[1][1]=="o" && matrica[2][1]=="o"){
        cout<<"Racunar je pobijedio"<<endl;
        return false;
    }
    else if(matrica[0][0]=="o" && matrica[1][0]=="o" && matrica[2][0]=="o"){
        cout<<"Racunar je pobijedio"<<endl;
        return false;
    }
    //---------------------------------------------------------------------

    else{
        return true;
    }
}

int evaluirajKoJePobijedio(vector<vector<string> > &matrica,string igrac,string protivnik)
{
    for(int i=0;i<3;i++)
    {
        if(matrica[i][0]==igrac && matrica[i][0]==matrica[i][2] && matrica[i][2]==igrac) return 10;
        else if(matrica[0][i]==protivnik && matrica[1][i]==protivnik && matrica[2][i]==protivnik) return -10;
    }
        //dijagonale
        if( matrica[0][0]==matrica[1][1] && matrica[1][1]==matrica[2][2])
        {
            if(matrica[0][0]==igrac) return 10;
            else if(matrica[0][0]==protivnik) return -10;
        }

         else if( matrica[0][2]==matrica[1][1] && matrica[1][1]==matrica[2][0])
        {
            if(matrica[0][0]==igrac) return 10;
            else if(matrica[0][0]==protivnik) return -10;
        }
        else return 0;

        return 0;
}
void upisUMatricu(int indexRed,int indexKolona,string znak,vector<vector<string> > &m)
{
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m[i].size();j++){
            if(i==indexRed && j==indexKolona) m[i][j]=znak;
        }
    }
}
//Vizuelni prikaz trenutne okoline
void CrtajTrenutnuMatricu(int broj,string znak,vector<vector<string> > &a)
{
    int indexRed;
    int indexKolona;
    if(broj==1){ indexRed=0;indexKolona=0;}
    if(broj==2){ indexRed=0;indexKolona=1;}
    if(broj==3){ indexRed=0;indexKolona=2;}
    if(broj==4){ indexRed=1;indexKolona=0;}
    if(broj==5){ indexRed=1;indexKolona=1;}
    if(broj==6){ indexRed=1;indexKolona=2;}
    if(broj==7){ indexRed=2;indexKolona=0;}
    if(broj==8){ indexRed=2;indexKolona=1;}
    if(broj==9){ indexRed=2;indexKolona=2;}


    //Upisujemo zadani izbor u matricu
    upisUMatricu(indexRed,indexKolona,znak,a);

    //Graficki template
     cout<<"  -----------"<<endl;
    cout<<" | "<<a[0][0]<<" | "<<a[0][1]<<" | "<<a[0][2]<<" |"<<endl;
    cout<<"  -----------"<<endl;
    cout<<" | "<<a[1][0]<<" | "<<a[1][1]<<" | "<<a[1][2]<<" |"<<endl;
    cout<<"  -----------"<<endl;
    cout<<" | "<<a[2][0]<<" | "<<a[2][1]<<" | "<<a[2][2]<<" |"<<endl;
    cout<<"  -----------"<<endl;

}

//funkcija za generisanje broja
int ispitajJeLiZauzetoPolje(vector<int> zauzetaPoljaMatrice)
{
    int SlobodnoMjesto=rand()%9;

    for(int i=0;i<zauzetaPoljaMatrice.size();i++)
    {
        if(zauzetaPoljaMatrice[i]!=SlobodnoMjesto) continue;
        else
        {
            SlobodnoMjesto=rand()%9;
            i=0;
        }
    }
    return SlobodnoMjesto;
}
//algoritam minmax za odabir najboljeg poteza,AI bota
int brojPoljaBot(vector<vector <string> > trenutnoStanjeMatrice)
{
    int najboljeRjesenje;

    //indexPolja
    int indexZauzetogPoljaMatrice;

    //ovdje cuvamo indexe zauzetih polja
    vector<int> zauzetaPoljaMatrice;

    //biljezimo koja su zauzeta polja matrice i zabranjujemo ih
    for(int i=0;i<trenutnoStanjeMatrice.size();i++){
        for(int j=0;j<trenutnoStanjeMatrice[i].size();j++)
            if(trenutnoStanjeMatrice[i][j]!=" ")
                {
                   if(i==0 && j==0) indexZauzetogPoljaMatrice=1;
                   else if(i==0 && j==1) indexZauzetogPoljaMatrice=2;
                   else if(i==0 && j==2) indexZauzetogPoljaMatrice=3;
                   else if(i==1 && j==0) indexZauzetogPoljaMatrice=4;
                   else if(i==1 && j==1) indexZauzetogPoljaMatrice=5;
                   else if(i==1 && j==2) indexZauzetogPoljaMatrice=6;
                   else if(i==2 && j==0) indexZauzetogPoljaMatrice=7;
                   else if(i==2 && j==1) indexZauzetogPoljaMatrice=8;
                   else if(i==2 && j==2) indexZauzetogPoljaMatrice=9;
                   zauzetaPoljaMatrice.push_back(indexZauzetogPoljaMatrice);
                   indexZauzetogPoljaMatrice=0;
                }
        }
        najboljeRjesenje=ispitajJeLiZauzetoPolje(zauzetaPoljaMatrice);

        return najboljeRjesenje;
}

int minmaxAlgoritam(vector<vector<string> > matrica,int dubina,bool jeMaksimalno,string igrac,string protivnik)
{
    bool rezultat=evaluirajKoJePobijedio(matrica,igrac,pobjednik);
    if(rezultat==10) return rezultat;
    else if(rezultat=-10)return rezultat;
}

int main(){
    //znak igraca
    string igrac;

    //znak protivnika
    string protivnik

    //znak koji igrac koristi
    string znak;

    //znak koji Bot koristi
    string znakBot;

    //inicijalizacija figura (mogucih izbora)
    string figure[2]={"x","o"};

    cout<<"Pravila igre :"<<endl;
    cout<<"Brojevi predstavljaju polja u koje zelite ubaciti 'x' ili 'o' "<<endl;
    cout<<"  -----------"<<endl;
    cout<<" | 1 | 2 | 3 |"<<endl;
    cout<<"  -----------"<<endl;
    cout<<" | 4 | 5 | 6 |"<<endl;
    cout<<"  -----------"<<endl;
    cout<<" | 7 | 8 | 9 |"<<endl;
    cout<<"  -----------"<<endl;

    //inicijalizacija ploce (okoline)
    vector<vector<string> > matrica(3, std::vector<string>(3," "));;

    //broj mogucih izbora polja za Bot-a
    const int Ploca[9]={1,2,3,4,5,6,7,8,9};
    //brojPolja koji ce random generisati racunar
    int RandomBrojPoljaBot;

    int brojPolja;
    bool dok_neko_ne_pobijedi=true;
   while(dok_neko_ne_pobijedi)
                {
                    cout<<"Unesite broj za polje koje zelite : ";
                    cin>>brojPolja;


                    //provjera broja
                    if(brojPolja<1 || brojPolja>9)
                    {
                        cout<<"Potrebno je da unesete cijeli broj izmedju 1 i 9 "<<endl;
                        cout<<"Unesite broj za polje koje zelite : ";
                        cin>>brojPolja;
                        cout<<endl;
                    }

                    cout<<"Unesite svoj znak : ";
                    cin>>znak;


                    if(znak!="x" && znak!="o")
                    {
                        cout<<"Potrebno je da unesete 'x' ili 'o' "<<endl;
                        cout<<"Unesite ponovo svoj znak : ";
                        cin>>znak;
                        cout<<endl;
                    }

                    CrtajTrenutnuMatricu(brojPolja,znak,matrica);

                    //Logika racunara Bot

                    //izbor figura
                    if(znak=="x")
                    {
                        znakBot="o";
                        protivnik=znakBot;
                        igrac=znak;
                    }
                    else if(znak=="o")
                        {
                            znakBot="x";
                            protivnik=znakBot;
                            igrac=znak;
                        }

                   //izbor polja Bota
                   RandomBrojPoljaBot=Ploca[rand()%9];

                    //Potez Bota
                   CrtajTrenutnuMatricu(brojPoljaBot(matrica),znakBot,matrica);


                dok_neko_ne_pobijedi=Provjera(matrica);
               }



    return 0;
}



