#include <iostream>
#include <mysql.h>
using namespace std;

char serverdb[] = "localhost";
char userdb[] = "proyecto";
char passworddb[] = "Umg$2019";
char database[] = "proyecto2"; //variables con el valor para la base de datos
int main() {
	
	
	MYSQL* connection; //puntero 
	long alumnoId; //objeto de la coneccion 
	string alumnoNombre;
	string correo;
	string telefono;
	string grado;
	string seccion;
	const char* query; //como puntero
	int promedio;
	int bimestre1;
	int bimestre2;
	int bimestre3;
	int bimestre4;
	string sql;//sql que voy a ejecutar
	int resul;
	int op;

	connection = mysql_init(0);         
    if(connection)
	{
		cout<< "la biblioteca msql se ha iniciado correctamente" << endl;
	    connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL,0 );
	     if(connection)
	{
		cout<< "la coneccion fue exitosa" << endl;
			cout<< "Por favor ingrese la opcion que desee del menu" << endl;
			cout<< "opcion 1: agregar alumno" << endl;
			cout<< "opcion 2: agregar Grado del alumno" << endl;
			cout<< "opcion 3: Agreagar notas del alumno" << endl;
			cout<< "opcion 4: Buscar un alumno" << endl;
			cout<< "opcion 5: Buscar un grado" << endl;
			cout<< "opcion 6: borrar un alumno o grado" << endl;
			cout<< "opcion 7: modificar los datos de un alumno" << endl;
			cout<< "opcion 8: Modificar los datos de un grado" << endl;
			cout<< "opcion 9: lista de los alumnos de un grado y seccion" << endl;
			cout<< "opcion 10: salir" << endl;
			cin>>op;
		switch(op){
			case 1:
					cout<< "ingrese el nombre completo del alumno"  << endl;
	               	getline(cin, alumnoNombre); // ingreso el nombre del alumno y lo guardo 
		            cout<< "ingrese el correo del alumno"  << endl;
		            getline(cin, correo);
		            cout<< "ingrese el telefono del alumno"  << endl;
		            getline(cin, telefono);
		            sql = "INSERT INTO proyecto2(alumno_nombre, correo, telefono, grado, seccion)  VALUES ('" + alumnoNombre + "' , '" + correo + "' ,'" + telefono + "' , '" + grado + "' ,'" + seccion + "' , )";
	             	query = sql.c_str(); // lo convierto en puntero 
		            resul = mysql_query(connection, query);
		if (resul == 0 ){
			cout << "registro guardado";
		}
		else {
			cout << "no fue posible guardar el registro" << mysql_error(connection) <<endl;
		}
				break;
			case 2:
					cout<< "ingrese el grado del alumno"  << endl;
	              	getline(cin, grado);
	             	cout<< "ingrese la seccion del alumno"  << endl;
	            	getline(cin, seccion);
	            	sql = "INSERT INTO proyecto2(alumno_nombre, correo, telefono, grado, seccion)  VALUES ('" + alumnoNombre + "' , '" + correo + "' ,'" + telefono + "' , '" + grado + "' ,'" + seccion + "' , )";
		query = sql.c_str(); // lo convierto en puntero 
		resul = mysql_query(connection, query);
		if (resul == 0 ){
			cout << "registro guardado";
		}
		else {
			cout << "no fue posible guardar el registro" << mysql_error(connection) <<endl;
		}
				break;
			case 3:
				cout<< "ingrese las noas del alumno de los bimestres 1,2,3 y 4"  << endl;
				cout<< "Ingrese la nota del primer bimestre"  << endl;
	               	getline(cin, bimestre1); // ingreso el nombre del alumno y lo guardo 
		          	cout<< "Ingrese la nota del segundo bimestre"  << endl;
	               	getline(cin, bimestre2);
	               	cout<< "Ingrese la nota del tercer bimestre"  << endl;
	               	getline(cin, bimestre3);
	               	cout<< "Ingrese la nota del cuarto bimestre"  << endl;
	               	getline(cin, bimestre4);
	               	
		            sql = "INSERT INTO proyecto2(alumno_nombre, correo, telefono, grado, seccion)  VALUES ('" + alumnoNombre + "' , '" + correo + "' ,'" + telefono + "' , '" + grado + "' ,'" + seccion + "' , )";
	             	query = sql.c_str(); // lo convierto en puntero 
		            resul = mysql_query(connection, query);
		if (resul == 0 ){
			cout << "registro guardado";
		}
		else {
			cout << "no fue posible guardar el registro" << mysql_error(connection) <<endl;
		}
		
		promedio = bimestre1+bimestre2+bimestre3+bimestre4/4;
				break;
			case 4:
				 MYSQL_ROW row; //consulta, ROW PARA UNA FILA
	  MYSQL_RES* data; //aculuma los registros, marcamos como puntero 
	  sql = "SELECT * FROM alumno";
	  query = sql.c_str();
	  resul = mysql_query(connection, query);
	  if (resul == 0 ){
			cout << "Se obtivieron los siguientes datos "<< endl;
			data = mysql_store_result(connection);
			int countColumns = mysql_num_fields(data);
			row = mysql_fetch_row(data);
			while(row = mysql_fetch_row(data))
			{
				for (int i = 0; i< countColumns; i++)
				{
					cout<< row[i] <<"/t";
				}
				cout<<endl;
			}
		}
		else {
			cout << "no fue posible obtener el registro " << mysql_error(connection) <<endl;
		}
				break;
			case 5:
					 MYSQL_ROW row; //consulta, ROW PARA UNA FILA
	                 MYSQL_RES* data; //aculuma los registros, marcamos como puntero 
	                 sql = "SELECT * FROM grado";
	                 query = sql.c_str();
	                resul = mysql_query(connection, query);
	                 if (resul == 0 ){
		            	cout << "Se obtivieron los siguientes datos "<< endl;
		              	data = mysql_store_result(connection);
		            	int countColumns = mysql_num_fields(data);
	            		row = mysql_fetch_row(data);
		             	while(row = mysql_fetch_row(data))
		         	{
				for (int i = 0; i< countColumns; i++)
				{
					cout<< row[i] <<"/t";
				}
				cout<<endl;
			}
		}
		else {
			cout << "no fue posible obtener el registro " << mysql_error(connection) <<endl;
		}
				
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				cout<<"Gracias por usar el programa";
				exit(0);
				break;
		}
		
	
	
		
		
	}
	else {
		cout<< "no se pudo establecer la coneccion " << mysql_error(connection) <<endl;
	}
	 
 	
		}
	
	else {
		cout<< "no es posible iniciar la biblioteca" << endl;
	}
	return 0;	
	
}



