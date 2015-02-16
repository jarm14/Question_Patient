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
		char *date;
		char *text;
		char *context;
		char *answer;
		char *comment;

	public:

		question(){
			id_question = 0;
			id_doctor = 0;
			id_patient = 0;
			date = new char[22];
			text = new char[1024];
			context = new char[2048];
			answer = new char[2048];
			comment = new char[2048];
		}

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

		void setDate(char dat[22]){
			strcpy(date,dat);
		}

		char *getDate(){
			return date;
		}

		void setContext(char cont[2048]){
		
			strcpy(context,cont);
		}

		char *getContext(){
			return context;
		}

		void setText(char tex[1024]){
		
			strcpy(text,tex);
		}

		char *getText(){
			return text;
		}

		void setAnswer(char answ[2048]){
		
			strcpy(answer,answ);
		}

		char *getAnswer(){
			return answer;
		}

		void setComment(char comm[2048]){
		
			strcpy(comment,comm);
		}

		char *getComent(){
			return comment;
		}
};