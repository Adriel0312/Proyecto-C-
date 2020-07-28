
class Register{
public:
	Register(){

	}


	static void write(std::string move,std::string date){
		ofstream txt;
		txt.open("Register.txt",ofstream::app);
		txt <<move+"|";
		txt <<date;
		txt.close();

	}

	static void recieve(std::string move){
		time_t rawtime;
  		struct tm * timeinfo;

  		time ( &rawtime );
  		timeinfo = localtime ( &rawtime );
  		std::string date= asctime (timeinfo);
  		write(move,date);

	}


};