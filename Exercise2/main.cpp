#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp"
#include <iomanip>
#include <string>

using namespace std;


int main()

{
    //leggo da file le informazioni necessarie: assumo che il file sia scritto nel giusto formato
        string fileNameI = "data.txt";
        string fileNameO = "result.txt";

        ofstream ofs(fileNameO);
        if (ofs.fail()){
            cerr << "Errore nell'apertura dell'output file" << endl;
            return 1;
        }

        //definisco le variabili che mi serviranno nell'esercizio
        size_t n = 0;
        double S = 0;
        double* w = nullptr;
        double* r = nullptr;

        //leggiamo da file i dati necessari a risolvere l'esercizio
        if (!UtilsLibrary::ImportData(fileNameI, n, S, w, r)){
            cerr << "Errore nella lettura del file di input" << endl;
            return 1;
        }

        //inizio a stampare le prime righe sul file di output
        ofs << "S = " << fixed << setprecision(2) << S << ", n = " << setprecision(0) << n << endl;
        cout << "S = " << fixed << setprecision(2) << S << ", n = " << setprecision(0) << n << endl;
        //stampo i due array in output
        ofs << "w = " << UtilsLibrary::array_to_stringa(w,n) << endl;
        cout << "w = " << UtilsLibrary::array_to_stringa(w,n) << endl;
        ofs << "r = " << UtilsLibrary::array_to_stringa(r,n) << endl;
        cout << "r = " << UtilsLibrary::array_to_stringa(r,n) << endl;

        //calcolo il valore finale del portafoglio e l'interesse totale
        ofs << "Rate of return del portfolio: " << setprecision(4) <<  UtilsLibrary::rate_of_return(w,r,n) << endl;
        cout << "Rate of return del portfolio: " << setprecision(4) <<  UtilsLibrary::rate_of_return(w,r,n) << endl;
        ofs << "V: " << fixed << setprecision(2) << UtilsLibrary::valore_finale_portfolio(w,r,S,n) << endl;
        cout << "V: " << fixed << setprecision(2) << UtilsLibrary::valore_finale_portfolio(w,r,S,n) << endl;


        //chiudo i file e rilascio la memoria
        ofs.close();
        delete [] w;
        delete [] r;

      
    return 0;
}

