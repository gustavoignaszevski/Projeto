#pragma once
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include <QTextEdit>
#include <QComboBox>
#include <QTimer>
#include "combat.h"

class Widget : public QWidget {
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);

private:
    Personagem jogador, inimigo;

    // UI jogador
    QLabel *jSprite;
    QLabel *jStats;
    QProgressBar *barra;

    // UI inimigo
    QLabel *iSprite;
    QLabel *iStats;

    // Indicador de elemento
    QLabel *jElementoLabel;
    QLabel *iElementoLabel;

    // Ações
    QPushButton *btnFogo;
    QPushButton *btnAgua;
    QPushButton *btnTerra;
    QPushButton *btnVento;

    QComboBox *comboUlt;
    QPushButton *btnUlt;

    QTextEdit *log;
    QTimer delay;

    QPushButton *btnAjuda;

    void mostrarAjuda();

    void atualizarUI();
    void atualizarUltimates();

    void turnoJogador(Elemento e);
    void usarUltimate();
    void turnoInimigo();

    void verificarFimDeJogo();
    void mostrarTelaFinal(bool vitoria);
    void resetarJogo();

};
