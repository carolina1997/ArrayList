typedef struct
{
    int id;
    char password[40];
    char name[30];
}Eusuario;

typedef struct
{
    int idUsuario;
    int id;
    char nombre[10000];
    float precio;
    int ventas;
    int stock;
}Eproducto;
/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [1] si no [0]
*
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [1] si no [0]
*
*/
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit);

/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [1] si no [0]
*
*/
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit);

/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [1] si no [0]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);


//constructores
Eusuario* newUsuario(void);
Eusuario* newUsuarioPar(int id, char* password, char* name);
Eproducto* newProducto(void);
Eproducto* newProductoPar(int idUsuario,int id,char* nombre,float precio,int stock,int ventas);
//usuario
void mostrarUsuario(Eusuario*);
void altaUsuario(ArrayList* listaUsuarios);
void bajaUsuario(ArrayList* listaUsuarios, ArrayList* listaProductos);
void modificarUsuario(ArrayList* listaUsuarios,ArrayList* listaProductos);
int verificarUsuario(ArrayList* listaUsuario,void* idUsuario, int opcion,int* i);
//productos
void mostrarProducto(Eproducto*);
int altaProducto(ArrayList* listaUsuarios,ArrayList* listaProductos);
void borrarPublicacion(ArrayList* listaUsuarios, ArrayList* listaProductos);
void modificarPublicacion(ArrayList* listaUsuarios,ArrayList* listaProductos);
void comprar(ArrayList* listaProductos);
//harcodeo
void harcodeoUsuario (ArrayList*);
void harcodeoProducto(ArrayList*);
//mostrar
void mostrar(ArrayList* listaProductos);
void mostrarListaUsu(ArrayList*);
void mostrarListaPro(ArrayList*);
void mostrarProductosDeUsuarios(ArrayList* listaProductos,ArrayList* listaUsuarios);
void mostrarProductoSinID(Eproducto*);
void mostrarProductosDe1usuario(int idUsuario ,ArrayList* listaProductos);
//archivos
void leerArchivoUsuarios(ArrayList* listaUsuarios);
void leerArchivoProductos(ArrayList* listaProductos);
void cargarArchivo(ArrayList* listaUsuarios,ArrayList* listaProductos);
//ordenar
int compareName(void* productoA,void* productoB);
int comparePrice(void* productoA,void* productoB);
int compareId(void* productoA,void* productoB);
