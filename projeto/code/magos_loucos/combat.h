#pragma once
#include <QString>

// elementos
enum class Elemento {
    Nenhum,
    Fogo,
    Agua,
    Terra,
    Vento
};

// entitade
struct Personagem {
    int hp;
    int hpMax;
    int atk;
    int def;
    Elemento elemento = Elemento::Nenhum;
    int barra = 0;
};

// logica de reações
struct ReactionResult {
    bool ocorreu = false;   // houve reação?
    int bonusDano = 0;      // dano extra (nao utilizado
    int cura = 0;           // cura aplicada (lama e leviatã)
    QString texto;          // texto da reação (para o log)
};

// logica de combate
int calcularDano(int atk, int def, bool ignoraDef = false);

ReactionResult resolverReacao(Personagem &atacante,
                              Personagem &alvo,
                              Elemento novoElemento,
                              bool vendaval = false);
