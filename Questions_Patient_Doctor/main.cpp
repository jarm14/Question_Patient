#include "doctor.h"
#include "patient.h"
#include "question.h"
#include "conexion_db.h"
#include <time.h>

char *current_date();

void main(){

	int flag,i=1;//declaracion de variables
	char op,date[18],patientName[512],patientSurName[512],email[320],text[1024],context[2048];
	doctor doctor;
	patient patient;

	do{//creacion del menu
		
		do{
			
			system("cls");
	
			cout<<"\t\t============PACIENTE============";
			cout<<"\n1.- Crear Pregunta";
			cout<<"\n2.- Ver Preguntas";
			cout<<"\n0.- Salir";
			cout<<"\nEscoja una opcion: ";
			cin>>(op); 

		}while(op!='1' && op!='2' && op!='0');

		if(op=='0'){
			
			break;
		}

		switch(op){
			case '1'://peticion del ingreso de preguntas

				question newQuestion;
				system("cls");
				cout<<"\t\t============PREGUNTA NUEVA============";
				
				cout<<"\nIngrese su nombre: ";
				fflush(stdin);
				gets(patientName);
				patient.setName(patientName);
				cout<<"Ingrese su apellido paterno: ";
				fflush(stdin);
				gets(patientSurName);
				patient.setSurName(patientSurName);
				cout<<"Ingrese su email: ";
				fflush(stdin);
				gets(email);
				patient.setEmail(email);
				patient.setId(i);
				doctor.setId_doctor(1);
				newQuestion.setIdQuestion(i);
				newQuestion.setIdPatient(patient.getId());
				newQuestion.setIdDoctor(doctor.getId_doctor());
				cout<<"Ingrese el contexto de la pregunta: ";
				fflush(stdin);
				gets(context);
				newQuestion.setContext(context);
				cout<<"Ingrese su pregunta: ";
				fflush(stdin);
				gets(text);
				newQuestion.setText(text);
				strcpy(date,current_date());
				newQuestion.setDate(date);
				
				i++;
				getch(); break;

			case '2'://impresion de preguntas
				connexion bd;
				question *questions;
				questions = bd.getQuestion();
				system("cls");
				cout<<"\t\t============PREGUNTAS RESPONDIDAS============";
				cout<<"\nID\tTexto de la pregunta";
				cout<<"\n\n"<<questions[i].getIdQuestion()<<"\t"<<questions[i].getText();

				getch(); break;

		}

	}while(op);   

}

char *current_date(){
	
	char dat[18];
	time_t now = time(0);// para ingresar el dia y hora actual
	struct tm  tstruct;
	char buf[18];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%x %X", &tstruct);//formato deseado
	strcpy(dat,buf);
	char *cur_date=dat;
	return cur_date;
}


