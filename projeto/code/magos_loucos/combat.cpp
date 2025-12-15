#include "combat.h"
#include <QtGlobal>

// calculo de dano
int calcularDano(int atk, int def, bool ignoraDef)
{
    if (ignoraDef)
        return atk;

    return atk - def;
}

// interação das reações
ReactionResult resolverReacao(Personagem &atacante,
                              Personagem &alvo,
                              Elemento novo,
                              bool vendaval)
{
    ReactionResult r;

    // sem reação
    if (alvo.elemento == Elemento::Nenhum || alvo.elemento == novo)
        return r;

    r.ocorreu = true;

    // energia extra da reação
    atacante.barra = qMin(100, atacante.barra + 10);

    // 🔥 + 💧 Vaporizar
    if ((alvo.elemento == Elemento::Fogo && novo == Elemento::Agua) ||
        (alvo.elemento == Elemento::Agua && novo == Elemento::Fogo)) {

        atacante.atk += 5;
        r.texto = "🔥 + 💧 Vaporizar! O seu ataque aumentou em 5!";
    }

    // 🌱 + 🔥 Queimadura
    else if ((alvo.elemento == Elemento::Terra && novo == Elemento::Fogo) ||
             (alvo.elemento == Elemento::Fogo && novo == Elemento::Terra)) {

        alvo.def -= 5;
        r.texto = "🌱 + 🔥 Queimadura! Defesa do alvo reduzida em 5!";
    }

    // 🌪️ + 🌱 Folhas Cortantes
    else if ((alvo.elemento == Elemento::Vento && novo == Elemento::Terra) ||
             (alvo.elemento == Elemento::Terra && novo == Elemento::Vento)) {

        r.texto = "🌪️ + 🌱 Folhas Cortantes! Defesa ignorada!";
    }

    // 🔥 + 🌪️ Explosão
    else if ((alvo.elemento == Elemento::Fogo && novo == Elemento::Vento) ||
             (alvo.elemento == Elemento::Vento && novo == Elemento::Fogo)) {

        alvo.atk -= 5;
        r.texto = "🔥 + 🌪️ Explosão! Ataque do alvo reduzido em 5!";
    }

    // 💧 + 🌱 Lama
    else if ((alvo.elemento == Elemento::Agua && novo == Elemento::Terra) ||
             (alvo.elemento == Elemento::Terra && novo == Elemento::Agua)) {

        r.cura = 10 + int((atacante.hpMax - atacante.hp) * 0.1);
        atacante.hp = qMin(atacante.hpMax, atacante.hp + r.cura);

        r.texto = QString("🌱 + 💧 Lama! O conjurador foi curado em %1 de vida!")
                      .arg(r.cura);
    }

    // 💧 + 🌪️ Névoa
    else if ((alvo.elemento == Elemento::Agua && novo == Elemento::Vento) ||
             (alvo.elemento == Elemento::Vento && novo == Elemento::Agua)) {

        atacante.def += 5;
        r.texto = "💧 + 🌪️ Névoa! Defesa do conjurador aumentou em 5!";
    }

    // remove o elemento se não for a ultimate vendaval
    if (vendaval)
        alvo.elemento = Elemento::Vento;
    else
        alvo.elemento = Elemento::Nenhum;

    return r;
}
