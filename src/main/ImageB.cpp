#include "ImageB.h"
#include "MyQT.h"

using std::cout;
using std::endl;

void ImageB::createMatrice()
{
#ifdef DEBUGVERBOSE
	cout<<"\033[35;43mDEBUGVERBOSE : createMatrice de ImageB\033[0m"<<endl;
#endif
	int largeur = dimension.getLargeur();
	int hauteur = dimension.getHauteur();
	matrice = new bool*[hauteur];
	for(int i=0; i<hauteur; i++)
	{
		matrice[i] = new bool[largeur];
		for(int j=0; j<largeur; j++)
			matrice[i][j] = false;
	}
#ifdef DEBUGVERBOSE
	cout<<"\033[36;43mDEBUGVERBOSE : Fin createMatrice de ImageB\033[0m"<<endl;
#endif
}

void ImageB::freeMatrice(bool **matrice, const Dimension &dimension)
{
#ifdef DEBUGVERBOSE
	cout<<"\033[35;43mDEBUGVERBOSE : freeMatrice de ImageB (matrice, dimension)\033[0m"<<endl;
#endif
	int hauteur = dimension.getHauteur();
	for(int i=0; i<hauteur; i++)
	{
		delete[] matrice[i];
	}
	delete[] matrice;
#ifdef DEBUGVERBOSE
	cout<<"\033[36;43mDEBUGVERBOSE : Fin freeMatrice de ImageB (matrice, dimension)\033[0m"<<endl;
#endif
}

void ImageB::freeMatrice()
{
#ifdef DEBUGVERBOSE
	cout<<"\033[35;43mDEBUGVERBOSE : freeMatrice de ImageB\033[0m"<<endl;
#endif
	freeMatrice(matrice, dimension);
	matrice = nullptr;
#ifdef DEBUGVERBOSE
	cout<<"\033[36;43mDEBUGVERBOSE : Fin freeMatrice de ImageB\033[0m"<<endl;
#endif
}

void ImageB::copyMatrice(bool **matrice, const Dimension &dimension, bool** matriceToCopy, const Dimension &dimensionOfMatriceToCopy)
{
#ifdef DEBUGVERBOSE
	cout<<"\033[35;43mDEBUGVERBOSE : copyMatrice de ImageB (matrice, dimension, matriceToCopy, dimensionOfMatriceToCopy)\033[0m"<<endl;
#endif
	int minLargeur = (dimension.getLargeur() < dimensionOfMatriceToCopy.getLargeur()) ? dimension.getLargeur() : dimensionOfMatriceToCopy.getLargeur();
	int minHauteur = (dimension.getHauteur() < dimensionOfMatriceToCopy.getHauteur()) ? dimension.getHauteur() : dimensionOfMatriceToCopy.getHauteur();
	for(int i=0; i<minHauteur; i++)
		for(int j=0; j<minLargeur; j++)
			matrice[i][j] = matriceToCopy[i][j];
#ifdef DEBUGVERBOSE
	cout<<"\033[36;43mDEBUGVERBOSE : Fin copyMatrice de ImageB (matrice, dimension, matriceToCopy, dimensionOfMatriceToCopy)\033[0m"<<endl;
#endif
}

void ImageB::copyMatrice(const ImageB &image)
{
#ifdef DEBUGVERBOSE
	cout<<"\033[35;43mDEBUGVERBOSE : copyMatrice de ImageB (image)\033[0m"<<endl;
#endif
	copyMatrice(matrice, dimension, image.matrice, image.dimension);
#ifdef DEBUGVERBOSE
	cout<<"\033[36;43mDEBUGVERBOSE : Fin copyMatrice de ImageB (image)\033[0m"<<endl;
#endif
}

ImageB::ImageB() : Image()
{
#ifdef DEBUG
	cout<<"\033[34;42mDEBUG : Constructeur par défaut de ImageB\033[0m"<<endl;
#endif
	setNom("ImageB sans nom");
	setDimension(dimension);
#ifdef DEBUG
	cout<<"\033[31;42mDEBUG : Fin Constructeur par défaut de ImageB\033[0m"<<endl;
#endif
}

ImageB::~ImageB()
{
#ifdef DEBUG
	cout<<"\033[32;41mDEBUG : Destructeur de ImageB\033[0m"<<endl;
#endif
	if(matrice != nullptr)
		freeMatrice();
#ifdef DEBUG
	cout<<"\033[34;41mDEBUG : Fin Destructeur de ImageB\033[0m"<<endl;
#endif
}

ImageB::ImageB(int id, const string &nom, const Dimension &dimension) : Image(id)
{
#ifdef DEBUG
	cout<<"\033[34;42mDEBUG : Constructeur d'initialisation complet de ImageB\033[0m"<<endl;
#endif
	setNom(nom);
	setDimension(dimension);
#ifdef DEBUG
	cout<<"\033[31;42mDEBUG : Fin Constructeur d'initialisation complet de ImageB\033[0m"<<endl;
#endif
}

ImageB::ImageB(int id, const string &nom) : Image(id)
{
#ifdef DEBUG
	cout<<"\033[34;42mDEBUG : Constructeur d'initialisation partiel de ImageB (id, nom)\033[0m"<<endl;
#endif
	setNom(nom);
	setDimension(dimension);
#ifdef DEBUG
	cout<<"\033[31;42mDEBUG : Fin Constructeur d'initialisation partiel de ImageB (id, nom)\033[0m"<<endl;
#endif
}

ImageB::ImageB(const string &nom) : Image()
{
#ifdef DEBUG
	cout<<"\033[34;42mDEBUG : Constructeur d'initialisation partiel de ImageB (nom)\033[0m"<<endl;
#endif
	setNom(nom);
	setDimension(dimension);
#ifdef DEBUG
	cout<<"\033[31;42mDEBUG : Fin Constructeur d'initialisation partiel de ImageB (nom)\033[0m"<<endl;
#endif
}

ImageB::ImageB(const ImageB &image) : Image(image)
{
#ifdef DEBUG
	cout<<"\033[34;42mDEBUG : Constructeur de copie de ImageB\033[0m"<<endl;
#endif
	setDimension(image.getDimension());
	copyMatrice(image);
#ifdef DEBUG
	cout<<"\033[31;42mDEBUG : Fin Constructeur de copie de ImageB\033[0m"<<endl;
#endif
}

ImageB& ImageB::operator=(const ImageB &image)
{
#ifdef DEBUGVERBOSE
	cout<<"\033[33;45mDEBUGVERBOSE : Opérateur d'affectation de ImageB\033[0m"<<endl;
#endif
	setId(image.getId());
	setNom(image.getNom());
	setDimension(image.getDimension());
	copyMatrice(image);
	return *this;
}

ostream& operator<<(ostream &outputStream, const ImageB &image)
{
#ifdef DEBUGVERBOSE
	cout<<"\033[33;46mDEBUGVERBOSE : Opérateur d'écriture de ImageB\033[0m"<<endl;
#endif
	outputStream<<"ImageB : "<<image.getNom()<<" "<<image.getDimension();
	return outputStream;
}

void ImageB::setDimension(const Dimension &dimension)
{
#ifdef DEBUGVERBOSE
	cout<<"\033[31;43mDEBUGVERBOSE : setDimension de ImageB\033[0m"<<endl;
#endif
	bool **oldMatrice = matrice;
	matrice = nullptr;
	Dimension oldDimension(this->dimension);
	this->dimension = dimension;
	createMatrice();
	if(oldMatrice != nullptr)
	{
		copyMatrice(matrice, this->dimension, oldMatrice, oldDimension);
		freeMatrice(oldMatrice, oldDimension);
	}
}

void ImageB::setBackground(bool couleur)
{
#ifdef DEBUGVERBOSE
	cout<<"\033[31;44mDEBUGVERBOSE : setBackground de ImageB\033[0m"<<endl;
#endif
	int largeur = dimension.getLargeur();
	int hauteur = dimension.getHauteur();
	for(int i=0; i<hauteur; i++)
		for(int j=0; j<largeur; j++)
			setPixel(j, i, couleur);
}

void ImageB::setPixel(int x, int y, bool couleur)
{
#ifdef DEBUGVERBOSE
	cout<<"\033[31;44mDEBUGVERBOSE : setPixel de ImageB\033[0m"<<endl;
#endif
	if (x >= 0 && x < dimension.getLargeur() && y >= 0 && y < dimension.getHauteur())
		matrice[y][x] = couleur;
}

bool ImageB::getPixel(int x, int y)const
{
#ifdef DEBUGVERBOSE
	cout<<"\033[32;44mDEBUGVERBOSE : getPixel de ImageB\033[0m"<<endl;
#endif
	if (x >= 0 && x < dimension.getLargeur() && y >= 0 && y < dimension.getHauteur())
		return matrice[y][x];
	//TODO: throw exception
	return -1;
}

//for some reason Couleur ImageB::couleurFalse(Couleur::NOIR); doesn't work
Couleur ImageB::couleurFalse(0xFF000000);
//for some reason Couleur ImageB::couleurTrue(Couleur::BLANC); doesn't work
Couleur ImageB::couleurTrue(0xFFFFFFFF);

void ImageB::Dessine()const
{
#ifdef DEBUGVERBOSE
	cout<<"\033[35;43mDEBUGVERBOSE : Dessine de ImageB\033[0m"<<endl;
#endif
	MyQT::ViewImage(*this);
#ifdef DEBUGVERBOSE
	cout<<"\033[36;43mDEBUGVERBOSE : Fin Dessine de ImageB\033[0m"<<endl;
#endif
}

void ImageB::exportToFile(const string &nomFichier, const string &formatFichier)const
{
#ifdef DEBUGVERBOSE
	cout<<"\033[35;43mDEBUGVERBOSE : exportToFile de ImageB\033[0m"<<endl;
#endif
	MyQT::ExportToFile(*this, nomFichier.c_str(), formatFichier.c_str());
#ifdef DEBUGVERBOSE
	cout<<"\033[36;43mDEBUGVERBOSE : Fin exportToFile de ImageB\033[0m"<<endl;
#endif
}
