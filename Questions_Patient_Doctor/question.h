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

		void setDate(char dat[18]){
		
			strcpy(date,dat);
		}

		char *getDate(){
		
			char *dat=date;
			return dat;
		}

		void setContext(char cont[2048]){
		
			strcpy(context,cont);
		}

		char *getContext(){
		
			char *cont=context;
			return cont;
		}

		void setText(char tex[1024]){
		
			strcpy(text,tex);
		}

		char *getText(){
		
			char *tex=text;
			return tex;
		}

		void setAnswer(char answ[2048]){
		
			strcpy(answer,answ);
		}

		char *getAnswer(){
		
			char *answ=answer;
			return answ;
		}

		void setComment(char comm[2048]){
		
			strcpy(comment,comm);
		}

		char *getComent(){
		
			char *comm=comment;
			return comm;
		}
};