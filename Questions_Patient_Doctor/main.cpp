#include "doctor.h"
#include "patient.h"
#include "question.h"
#include "conexion_db.h"
#include "test.h"
#include <time.h>
#include <string.h>

using namespace std;

char *current_date();
int entero();

void main(){

	int i,flag;//declaracion de variables
	char op,date[18],patientName[512],patientSurName[512],email[320],text[1024],context[2048];
	patient *patients;
	int id,count;

	do{
		connexion bd;
		count=bd.getCountPatient();
		patients=bd.getPatient();
		flag=0;
		system("cls");
		cout<<"\t\t============BINEVENIDO AL SISTEMA DE PACIENTES============";
		cout<<"\n\nPorfavor ingresa tu ID: ";
		cin>>(id);

		for(i=0;i<count;i++){//comprueba el id del usuario
	
			if(id==patients->getId()){
		
				flag=1;
				i=count;
				patients--;
			}
			patients++;
		}
		if(flag==0){
		
			cout<<"ID incorrecto";
			getch();
		}

	}while(flag==0);


	do{//creacion del menu
		
		do{
			
			system("cls");
	
			cout<<"\t\t============BIENVENIDO " <<patients->getName()<<"============";
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
				cout<<"\n\nIngrese el contexto de pregunta: ";
				cout<<"\n\nIngrese la pregunta: ";
				
				getch(); break;

			case '2'://impresion de preguntas
				char cOp;
				do{
					connexion bd;
					int count;
					int id;
					count=bd.getCount();
					question *questions;
					questions=bd.getQuestion();
					system("cls");
					cout<<"\t\t============PREGUNTAS RESPONDIDAS============";
					cout<<"\nID\tTexto de la pregunta";
					
					for(i=0;i<count;i++){
						
						char answer[2048]="";
					
						if(strcmp(answer,questions->getAnswer())!=0){
					
							cout<<"\n\n"<<questions->getIdQuestion()<<"\t"<<questions->getText();
						}
						questions++;
					}
				
					do{
						cout<<"\n\n Escoge el ID de una pregunta: ";
						cin>>(id);
						questions=bd.getQuestion();
						flag=0;
						i=0;

						for(i=0;i<count;i++){//comprueba el id del usuario
	
							if(id==questions->getIdQuestion()){
		
								flag=1;
								i=count;
								questions--;
							}
							questions++;
						}
						if(flag==0){
		
							cout<<"ID incorrecto";
							getch();
						}
					}while(flag==0);

					do{
					
						system("cls");
						cout<<"\t\t============PREGUNTAS RESPONDIDAS============";
						cout<<"\n\nLa pregunta fue: "<<questions->getText();
						cout<<"\nLa respuesta es: "<<questions->getAnswer();
						cout<<"\nDesea ver otra pregunta (s/n): ";
						cin>>(cOp);

					}while(cOp!='n' && cOp!='s');

				}while(cOp!='n');
				
				break;

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

int entero()
{
	char *pass = new char[10];
	int conta = 0;
	int i = 0, punto = 0, acm = 0;
	while (pass[i] != 13 || i<1)
	{
		pass[i] = _getch();
		if ((pass[i]>32 && i<20) && (pass[i] >= 48 && pass[i] <= 57))
		{
			printf_s("%c", pass[i]);
			i++;
		}
		else if (pass[i] == 8 && i>0)
		{
			putchar(8);
			putchar(' ');
			putchar(8);
			i--;
		}
	}
	pass[i] = '\0';
	int entero = atoi(pass);
	return entero;

}

