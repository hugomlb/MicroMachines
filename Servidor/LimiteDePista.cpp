#include "LimiteDePista.h"
#define VIDA_MAX_DE_CARRO 1000

LimiteDePista::LimiteDePista() {
}

void LimiteDePista::interactuar(Carro *unCarro) {
  unCarro -> recibirDanio(VIDA_MAX_DE_CARRO);
}

LimiteDePista::~LimiteDePista() {
}
