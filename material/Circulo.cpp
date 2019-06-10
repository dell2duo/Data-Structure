
#include "Circulo.h"
#include <cmath>

using namespace std;


Circulo::Circulo(const Ponto &p, float raio_) : FigBase(p) {
	raio = raio_;
}

void Circulo::setRaio(float r) {
	raio = r;
}
    
float Circulo::getRaio() const {
	return raio;
}
    
//O ponto p esta dentro do circulo <-> a distancia entre o p e o interior do circulo for menor do que o raio
bool Circulo::contem(const Ponto &p) const {
	float dist = sqrt(pow(p.getX()-this->p0.getX(), 2) + pow(p.getY()-this->p0.getY(), 2)); //distancia entre p e o interior do circulo
	return  dist < raio;
}