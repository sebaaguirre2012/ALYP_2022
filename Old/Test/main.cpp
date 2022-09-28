#include <iostream>
using namespace std;

const int NoEncontrado = -1;
const int TopeValorCampo = 30;
const int TopeCantidadCampos = 4;
const int TopeCantidadRegistros = 38;
const int TopeValorRegistro = 110;
const char FinDeLinea = '\n';
const char FinDeCadena = '\0';
const char Coma = ',';
const string DEBUG = "--[DEBUG]--: ";

struct Campo {
	char valor[TopeValorCampo];
};

struct Registro {
	int cantidadCampos;
	Campo campos[TopeCantidadCampos];
};

struct ArchivoCsv {
	int cantidadRegistros;
	Registro registros[TopeCantidadRegistros];
};



int BuscarCaracter(char *cadena, char c) {
	int pos = NoEncontrado;
	for (int i = 0; *cadena and pos == NoEncontrado; ++cadena, ++i) {
		if (*cadena == c) 
			pos = i;
	}
	return pos;
}

void Copiar(char *origen, char *destino) {
    while (*destino++ = *origen++);
}

void CopiarHataSeparador(char *origen, char *destino, char separador) {
    while ((*destino++ = *origen++) and (*origen != separador));
}

int ContarCaracteres(char *cadena) {
    char* inicio = cadena;
	while (*cadena++);
	return cadena - inicio - 1;
}

void Concatenar(char *cadena, char* subcadena) {
    Copiar(subcadena, cadena + ContarCaracteres(cadena));
}

void MostrarRegistro(Registro* registro) {
	for (int i = 0; i < registro->cantidadCampos; ++i) {
		cout << "Campo " << i << " : " << registro->campos[i].valor << endl;
	}
}

void CopiarCaracter(char* origen, char* destino) {
	*destino = *origen;
}

bool EsFinDeLinea(char c) {
	return c == FinDeLinea;
}

void CargarArchivoCsv(ArchivoCsv* archivo, char* cRegistro) {
	cout << DEBUG << cRegistro << endl;
	archivo->registros[TopeCantidadRegistros];
	archivo->cantidadRegistros++;
}

void CargarRegistro(char* cRegistro, Registro* registro) {
}

Registro* CrearRegistro(char* cRegistro) {
	Registro* nuevoRegistro = new Registro;
	CargarRegistro(cRegistro, nuevoRegistro);
	return nuevoRegistro;
}

void Parsear(char* batallasCSV, ArchivoCsv* archivo) {
	char cRegistro[TopeValorRegistro];
	for (int i = 0; i <= 2; ++i, ++batallasCSV) {
		char* pRegistro = cRegistro;
		for (; not EsFinDeLinea(*batallasCSV); ) {
			*pRegistro++ = *batallasCSV++;
		}
		*pRegistro = FinDeCadena;
		CargarArchivoCsv(archivo, cRegistro);
	}
}

void MostrarInformeBatallas(char batallasCSV1[], char batallasCSV2[]) {
	ArchivoCsv archivo;

	Parsear(batallasCSV1, &archivo);
}

void Pruebas() {

}

Campo* CrearCampo(char* valor) {
	Campo* campo = new Campo;
	Copiar(valor, campo->valor);
	return campo;
}

int main() {
	char batallas1[]="battle_number,name,attacker_king,defender_king\n1,Battle of the Golden Tooth,Joffrey/Tommen Baratheon,Robb Stark\n2,Battle at the Mummer\'s Ford,Joffrey/Tommen Baratheon,Robb Stark\n3,Battle of Riverrun,Joffrey/Tommen Baratheon,Robb Stark\n4,Battle of the Green Fork,Robb Stark,Joffrey/Tommen Baratheon\n5,Battle of the Whispering Wood,Robb Stark,Joffrey/Tommen Baratheon\n6,Battle of the Camps,Robb Stark,Joffrey/Tommen Baratheon\n7,Sack of Darry,Joffrey/Tommen Baratheon,Robb Stark\n8,Battle of Moat Cailin,Balon/Euron Greyjoy,Robb Stark\n9,Battle of Deepwood Motte,Balon/Euron Greyjoy,Robb Stark\n10,Battle of the Stony Shore,Balon/Euron Greyjoy,Robb Stark\n11,Battle of Torrhen\'s Square,Robb Stark,Balon/Euron Greyjoy\n12,Battle of Winterfell,Balon/Euron Greyjoy,Robb Stark\n13,Sack of Torrhen\'s Square,Balon/Euron Greyjoy,Balon/Euron Greyjoy\n14,Sack of Winterfell,Joffrey/Tommen Baratheon,Robb Stark\n15,Battle of Oxcross,Robb Stark,Joffrey/Tommen Baratheon\n16,Siege of Storm\'s End,Stannis Baratheon,Renly Baratheon\n17,Battle of the Fords,Joffrey/Tommen Baratheon,Robb Stark\n18,Sack of Harrenhal,Robb Stark,Joffrey/Tommen Baratheon\n19,Battle of the Crag,Robb Stark,Joffrey/Tommen Baratheon\n20,Battle of the Blackwater,Stannis Baratheon,Joffrey/Tommen Baratheon\n21,Siege of Darry,Robb Stark,Joffrey/Tommen Baratheon\n22,Battle of Duskendale,Robb Stark,Joffrey/Tommen Baratheon\n23,Battle of the Burning Septry,,\n24,Battle of the Ruby Ford,Joffrey/Tommen Baratheon,Robb Stark\n25,Retaking of Harrenhal,Joffrey/Tommen Baratheon,\n26,The Red Wedding,Joffrey/Tommen Baratheon,Robb Stark\n27,Siege of Seagard,Robb Stark,Joffrey/Tommen Baratheon\n28,Battle of Castle Black,Stannis Baratheon,Mance Rayder\n29,Fall of Moat Cailin,Joffrey/Tommen Baratheon,Balon/Euron Greyjoy\n30,Sack of Saltpans,,\n31,Retaking of Deepwood Motte,Stannis Baratheon,Balon/Euron Greyjoy\n32,Battle of the Shield Islands,Balon/Euron Greyjoy,Joffrey/Tommen Baratheon\n33,'Invasion of Ryamsport, Vinetown, and Starfish Harbor',Balon/Euron Greyjoy,Joffrey/Tommen Baratheon\n34,Second Seige of Storm\'s End,Joffrey/Tommen Baratheon,Stannis Baratheon\n35,Siege of Dragonstone,Joffrey/Tommen Baratheon,Stannis Baratheon\n36,Siege of Riverrun,Joffrey/Tommen Baratheon,Robb Stark\n37,Siege of Raventree,Joffrey/Tommen Baratheon,Robb Stark\n38,Siege of Winterfell,Stannis Baratheon,Joffrey/Tommen Baratheon\n";
	char batallas2[]="battle_number,location,region,attacker_outcome\n1,Golden Tooth,The Westerlands,win\n2,Mummer\'s Ford,The Riverlands,win\n3,Riverrun,The Riverlands,win\n4,Green Fork,The Riverlands,loss\n5,Whispering Wood,The Riverlands,win\n6,Riverrun,The Riverlands,win\n7,Darry,The Riverlands,win\n8,Moat Cailin,The North,win\n9,Deepwood Motte,The North,win\n10,Stony Shore,The North,win\n11,Torrhen\'s Square,The North,win\n12,Winterfell,The North,win\n13,Torrhen\'s Square,The North,win\n14,Winterfell,The North,win\n15,Oxcross,The Westerlands,win\n16,Storm\'s End,The Stormlands,win\n17,Red Fork,The Riverlands,loss\n18,Harrenhal,The Riverlands,win\n19,Crag,The Westerlands,win\n20,King\'s Landing,The Crownlands,loss\n21,Darry,The Riverlands,win\n22,Duskendale,The Crownlands,loss\n23,,The Riverlands,win\n24,Ruby Ford,The Riverlands,win\n25,Harrenhal,The Riverlands,win\n26,The Twins,The Riverlands,win\n27,Seagard,The Riverlands,win\n28,Castle Black,Beyond the Wall,loss\n29,Moat Cailin,The North,win\n30,Saltpans,The Riverlands,win\n31,Deepwood Motte,The North,win\n32,Shield Islands,The Reach,win\n33,'Ryamsport, Vinetown, Starfish Harbor',The Reach,win\n34,Storm\'s End,The Stormlands,win\n35,Dragonstone,The Stormlands,win\n36,Riverrun,The Riverlands,win\n37,Raventree,The Riverlands,win\n38,Winterfell,The North,\n";

	MostrarInformeBatallas(batallas1, batallas2);

	return 0;
}



