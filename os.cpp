int main (){

      string s;
        cin  >> s;
        cout << s << endl;
        ofstream f_man;    // file manupulation; importing  ofstream clas
    int run_or_exit=1; // for running the  program  many tie;
    while(run_or_exit!=0 && run_or_exit==1){
         int rq=input();
    switch(rq){
          
        case 1:
        {
            string f_name , ext;
             cout << "enter new file name" << endl;
            cin >> f_name;
             cout << " enter the file ext please include .  first" << endl;
             cin >> ext;
            string full_nane= f_name+ ext;
            f_man.open(full_nane);
            cout <<" file created " << endl;    
            break;

        }
        case 2 :{
      
             
             

        }
        default:
         cout <<"wrong input" << endl;
         break;
    } 
   cout << "if continue press 1 or press 0 "<< endl;
   cin >> run_or_exit;
    }
    if(run_or_exit==0)
        cout << "exit" << endl;
    else
        cout << "press wrong key  exiting  the program";
        f_man.close();
      return 0;
}