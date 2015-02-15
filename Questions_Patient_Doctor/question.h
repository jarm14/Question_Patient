#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std;

class question{

	private:
		
		int id_question;
		int id_doctor;
		int id_patient;
		char date[18];
		char patient_id[32];
		char text[1024];
		char context[2048];
		char answer[2048];
		char comment[2048];

	public:

		void setIdQuestion(int id){
		
			id_question = id;
		}

		int getIdQuestion(){
		
			return id_question;
		}

		void setIdDoctor(int id){
		
			id_doctor = id;
		}

		int getIdDoctor(){
		
			return id_doctor;
		}

		void setIdPatient(int id){
		
			id_patient = id;
		}

		int getIdPatient(){
		
			return id_patient;
		}

		void setDate(){
		
			time_t now = time(0);// para ingresar el dia y hora actual
			struct tm  tstruct;
			char buf[80];
			tstruct = *localtime(&now);
			strftime(buf, sizeof(buf), "%Y/%m/%d %X", &tstruct);//formato deseado
			strcpy(date,buf);
		}

		char *getDate(){
		
			char *dat=date;
			return dat;
		}

		void setContext(){
		
			cout<<"\nIngrese el contexto de la pregunta: ";
			fflush(stdin);
			gets(context);
		}

		char *getContext(){
		
			char *cont=context;
			return cont;
		}

		void setText(){
		
			cout<<"\nIngrese la pregunta: ";
			fflush(stdin);
			gets(text);
		}

		char *getText(){
		
			char *tex=text;
			return tex;
		}

		void setAnswer(){
		
			cout<<"\nIngrese la respuesta: ";
			fflush(stdin);
			gets(answer);
		}

		char *getAnswer(){
		
			char *answ=answer;
			return answ;
		}

		void setComment(){
		
			cout<<"\nIngrese un comentario: ";
			fflush(stdin);
			gets(comment);
		}

		char *getComent(){
		
			char *comm=comment;
			return comm;
		}
};