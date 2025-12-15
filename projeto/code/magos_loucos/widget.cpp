#include "widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QRandomGenerator>
#include <QDialog>

bool jogoEncerrado = false;

static QString nomeElemento(Elemento e)
{
    switch (e) {
    case Elemento::Fogo:  return "Fogo";
    case Elemento::Agua:  return "Água";
    case Elemento::Terra: return "Terra";
    case Elemento::Vento: return "Vento";
    default: return "";
    }
}

static QString elementoEmoji(Elemento e)
{
    switch (e) {
    case Elemento::Fogo:  return "🔥";
    case Elemento::Agua:  return "💧";
    case Elemento::Terra: return "🌱";
    case Elemento::Vento: return "🌪️";
    default: return "";
    }
}

// ==================== CONSTRUTOR ====================
Widget::Widget(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Magos Loucos");
    resize(1000, 600);

    // ===== Dados =====
    jogador = {200, 200, 20, 10};
    inimigo = {200, 200, 20, 10};

    // ==================== JOGADOR ====================
    jElementoLabel = new QLabel("");
    jElementoLabel->setAlignment(Qt::AlignCenter);
    jElementoLabel->setFixedHeight(30);

    jSprite = new QLabel("🧙");
    jSprite->setAlignment(Qt::AlignCenter);
    jSprite->setFixedSize(180, 180);
    jSprite->setStyleSheet("font-size: 96px;");

    jStats = new QLabel;
    barra = new QProgressBar;
    barra->setRange(0, 100);

    QVBoxLayout *jLayout = new QVBoxLayout;
    jLayout->addWidget(jElementoLabel);
    jLayout->addWidget(jSprite);
    jLayout->addWidget(jStats);
    jLayout->addWidget(barra);

    // inimigo
    iElementoLabel = new QLabel("");
    iElementoLabel->setAlignment(Qt::AlignCenter);
    iElementoLabel->setFixedHeight(30);

    iSprite = new QLabel("🧙‍♀️");
    iSprite->setAlignment(Qt::AlignCenter);
    iSprite->setFixedSize(180, 180);
    iSprite->setStyleSheet("font-size: 96px;");

    iStats = new QLabel;

    QVBoxLayout *iLayout = new QVBoxLayout;
    iLayout->addWidget(iElementoLabel);
    iLayout->addWidget(iSprite);
    iLayout->addWidget(iStats);

    // botões de ação
    btnFogo  = new QPushButton("🔥 Fogo");
    btnAgua  = new QPushButton("💧 Água");
    btnTerra = new QPushButton("🌱 Terra");
    btnVento = new QPushButton("🌪️ Vento");

    comboUlt = new QComboBox;
    comboUlt->addItem("☄️ Meteoro do Fulgor (60)");
    comboUlt->addItem("🐉 Corrente do Leviatã (40)");
    comboUlt->addItem("⛰️ Terra Primordial (50)");
    comboUlt->addItem("🌀 Vendaval Uivante (70)");
    comboUlt->addItem("🛰️ Laser Orbital (100)");
    comboUlt->addItem("💠 Zoltrak (30)");

    btnUlt = new QPushButton("Usar Ultimate");

    QVBoxLayout *acoes = new QVBoxLayout;
    acoes->setAlignment(Qt::AlignCenter);
    acoes->addWidget(btnFogo);
    acoes->addWidget(btnAgua);
    acoes->addWidget(btnTerra);
    acoes->addWidget(btnVento);
    acoes->addSpacing(15);
    acoes->addWidget(comboUlt);
    acoes->addWidget(btnUlt);

    // log de texto
    log = new QTextEdit;
    log->setReadOnly(true);
    log->setFixedHeight(130);

    // layout princiapl
    QHBoxLayout *top = new QHBoxLayout;
    top->addLayout(jLayout, 1);
    top->addLayout(acoes, 1);
    top->addLayout(iLayout, 1);

    QVBoxLayout *main = new QVBoxLayout(this);
    main->addLayout(top);
    main->addWidget(log);

    // conexões
    connect(btnFogo,  &QPushButton::clicked, this, [=]{ turnoJogador(Elemento::Fogo);  });
    connect(btnAgua,  &QPushButton::clicked, this, [=]{ turnoJogador(Elemento::Agua);  });
    connect(btnTerra, &QPushButton::clicked, this, [=]{ turnoJogador(Elemento::Terra); });
    connect(btnVento, &QPushButton::clicked, this, [=]{ turnoJogador(Elemento::Vento); });

    connect(btnUlt, &QPushButton::clicked, this, &Widget::usarUltimate);
    connect(comboUlt, &QComboBox::currentIndexChanged,
            this, &Widget::atualizarUltimates);

    delay.setSingleShot(true);
    connect(&delay, &QTimer::timeout, this, &Widget::turnoInimigo);

    atualizarUI();

    // botão de ajuda
    btnAjuda = new QPushButton("?");
    btnAjuda->setFixedSize(30, 30);
    btnAjuda->setToolTip("Ajuda / Regras do jogo");

    connect(btnAjuda, &QPushButton::clicked,
            this, &Widget::mostrarAjuda);

    QHBoxLayout *topBar = new QHBoxLayout;
    topBar->addStretch();
    topBar->addWidget(btnAjuda);

    main->insertLayout(0, topBar);

    log->append(">> Que começe a loucura magica!");

}

// turno do jogador
void Widget::turnoJogador(Elemento e)
{
    btnFogo->setEnabled(false);
    btnAgua->setEnabled(false);
    btnTerra->setEnabled(false);
    btnVento->setEnabled(false);
    btnUlt->setEnabled(false);

    jogador.barra = qMin(100, jogador.barra + 5);

    ReactionResult r = resolverReacao(jogador, inimigo, e);

    int dano;
    bool ignoraDef = r.texto.contains("Folhas");
    dano = ignoraDef ? jogador.atk : calcularDano(jogador.atk, inimigo.def);
    dano += r.bonusDano;

    inimigo.hp -= dano;

    if (r.ocorreu)
        log->append(">> " + r.texto);

    log->append(QString(">> Jogador usou %1, causando %2 de dano")
                    .arg(nomeElemento(e))
                    .arg(dano));

    if (!r.ocorreu)
        inimigo.elemento = e;

    log->append("");
    atualizarUI();
    delay.start(1000);

    verificarFimDeJogo();
}


// turno do inimigo
void Widget::turnoInimigo()
{
    if(jogoEncerrado ==true) {
        return;
    }
    Elemento e = static_cast<Elemento>(
        QRandomGenerator::global()->bounded(1, 5));

    ReactionResult r = resolverReacao(inimigo, jogador, e);

    int dano;
    bool ignoraDef = r.texto.contains("Folhas");
    dano = ignoraDef ? inimigo.atk : calcularDano(inimigo.atk, jogador.def);
    dano += r.bonusDano;

    jogador.hp -= dano;

    if (r.ocorreu)
        log->append("<< " + r.texto);

    log->append(QString("<< Inimigo usou %1, causando %2 de dano")
                    .arg(nomeElemento(e))
                    .arg(dano));

    if (!r.ocorreu)
        jogador.elemento = e;

    log->append("");
    btnFogo->setEnabled(true);
    btnAgua->setEnabled(true);
    btnTerra->setEnabled(true);
    btnVento->setEnabled(true);

    atualizarUI();

    verificarFimDeJogo();
}


// ultimates
void Widget::atualizarUltimates()
{
    int custos[] = {60, 40, 50, 70, 100, 30};
    btnUlt->setEnabled(jogador.barra >= custos[comboUlt->currentIndex()]);
}

void Widget::usarUltimate()
{
    int idx = comboUlt->currentIndex();
    int custos[] = {60, 40, 50, 70, 100, 30};

    if (jogador.barra < custos[idx])
        return;

    jogador.barra -= custos[idx];

    ReactionResult r;
    int dano = 0;

    // Meteoro
    if (idx == 0) {
        r = resolverReacao(jogador, inimigo, Elemento::Fogo);
        int base = jogador.atk * 2.5;
        dano = calcularDano(base, inimigo.def) + r.bonusDano;
        inimigo.hp -= dano;

        if (r.ocorreu)
            log->append(">> " + r.texto);

        log->append(QString(
                        ">> ☄️ Um Meteoro do Fulgor cai do céu! causando %1 de dano"
                        ).arg(dano));

        if (!r.ocorreu)
            inimigo.elemento = Elemento::Fogo;
    }

    // Leviatã
    else if (idx == 1) {
        int cura = 30 + int((jogador.hpMax - jogador.hp) * 0.2);
        jogador.hp = qMin(jogador.hpMax, jogador.hp + cura);
        jogador.elemento = Elemento::Nenhum;

        log->append(QString(
                        ">> 🐉 O leviatã das profundezas lhe concede sua benção, recuperando %1 de vida e limpando o elemento aplicado atual"
                        ).arg(cura));
    }

    // Terra Primordial
    else if (idx == 2) {
        jogador.def += 15;
        inimigo.def -= 5;

        log->append(
            ">> ⛰️ Ao seu redor é emanado terra primordial, lhe fazendo se sentir mais saudável do que nunca! Defesa +15, Defesa inimiga -5"
            );
    }

    // Vendaval
    else if (idx == 3) {
        r = resolverReacao(jogador, inimigo, Elemento::Vento, true);
        int base = jogador.atk * 2;
        dano = calcularDano(base, inimigo.def) + r.bonusDano;
        inimigo.hp -= dano;

        if (r.ocorreu)
            log->append(">> " + r.texto);

        log->append(QString(
                        ">> 🌀 Um vendaval uivante atravessa o inimigo com tudo! causando %1 de dano. O vendaval é persistente e mantém o elemento de vento no inimigo!"
                        ).arg(dano));
    }

    // Laser orbital
    else if (idx == 4) {
        dano = jogador.atk * 3;
        inimigo.hp -= dano;

        log->append(QString(
                        ">> 🛰️ Algo brilhoso e poderoso cai do céu, pulverizando completamente seu inimigo, causando %1 de dano verdadeiro!"
                        ).arg(dano));
    }

    // Zoltrak
    else if (idx == 5) {
        int efeito = QRandomGenerator::global()->bounded(5);

        switch (efeito) {
        case 0: jogador.atk += 2;
            log->append(">> Zoltrak fortaleceu o conjurador! (+2 ATK)");
            break;
        case 1: inimigo.def -= 2;
            log->append(">> Zoltrak enfraqueceu o inimigo! (-2 DEF)");
            break;
        case 2: {
            int cura = 5 + int((jogador.hpMax - jogador.hp) * 0.05);
            jogador.hp = qMin(jogador.hpMax, jogador.hp + cura);
            log->append(QString(">> Zoltrak curou o conjurador em %1 de vida").arg(cura));
            break;
        }
        case 3: inimigo.atk -= 2;
            log->append(">> Zoltrak drenou o ataque do inimigo! (-2 ATK)");
            break;
        case 4: jogador.def += 2;
            log->append(">> Zoltrak fortaleceu a defesa do conjurador! (+2 DEF)");
            break;
        }

        int base = jogador.atk * 1.5;
        dano = calcularDano(base, inimigo.def);
        inimigo.hp -= dano;

        log->append(QString(
                        ">> 💠 Um poderoso e focado Zoltrak foi utilizado contra o inimigo, o perfurando e causando %1 de dano!"
                        ).arg(dano));
    }

    log->append("");

    atualizarUI();
    btnUlt->setEnabled(false);
    delay.start(1000);

    verificarFimDeJogo();
}


// UI
void Widget::atualizarUI()
{
    jStats->setText(
        QString("HP: %1\nATK: %2\nDEF: %3")
            .arg(jogador.hp).arg(jogador.atk).arg(jogador.def)
        );

    iStats->setText(
        QString("HP: %1\nATK: %2\nDEF: %3")
            .arg(inimigo.hp).arg(inimigo.atk).arg(inimigo.def)
        );

    barra->setValue(jogador.barra);

    jElementoLabel->setText(elementoEmoji(jogador.elemento));
    iElementoLabel->setText(elementoEmoji(inimigo.elemento));

    atualizarUltimates();
}

void Widget::verificarFimDeJogo()
{
    if (inimigo.hp <= 0) {
        mostrarTelaFinal(true);   // vitória
    }
    else if (jogador.hp <= 0) {
        mostrarTelaFinal(false);  // derrota
    }
}

void Widget::mostrarTelaFinal(bool vitoria)
{
    jogoEncerrado = true;
    // Bloqueia ações
    btnFogo->setEnabled(false);
    btnAgua->setEnabled(false);
    btnTerra->setEnabled(false);
    btnVento->setEnabled(false);
    btnUlt->setEnabled(false);

    QDialog *dialog = new QDialog(this);
    dialog->setModal(true);
    dialog->setFixedSize(400, 250);

    QLabel *titulo = new QLabel(dialog);
    titulo->setAlignment(Qt::AlignCenter);
    titulo->setStyleSheet("font-size: 26px; font-weight: bold;");

    QLabel *texto = new QLabel(dialog);
    texto->setAlignment(Qt::AlignCenter);
    texto->setWordWrap(true);

    if (vitoria) {
        dialog->setWindowTitle("Vitória!");
        titulo->setText("🎉 VITÓRIA 🎉");
        texto->setText("Você derrotou a criatura mágica!\n\nSua loucura elemental prevaleceu!");
    } else {
        dialog->setWindowTitle("Derrota");
        titulo->setText("💀 DERROTA 💀");
        texto->setText("Seu mago elouqueceu de vez...\n\nTalvez na próxima tentativa.");
    }

    QPushButton *btnReiniciar = new QPushButton("Elouquecer novamente?");
    QPushButton *btnSair = new QPushButton("Sair");

    connect(btnReiniciar, &QPushButton::clicked, this, [=] {
        dialog->accept();
        resetarJogo();
    });

    connect(btnSair, &QPushButton::clicked, dialog, &QDialog::reject);

    QHBoxLayout *botoes = new QHBoxLayout;
    botoes->addWidget(btnReiniciar);
    botoes->addWidget(btnSair);

    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(titulo);
    layout->addWidget(texto);
    layout->addStretch();
    layout->addLayout(botoes);

    dialog->exec();
}

void Widget::resetarJogo()
{
    jogoEncerrado = false;

    jogador = {200, 200, 20, 10};
    inimigo = {200, 200, 20, 10};

    jogador.elemento = Elemento::Nenhum;
    inimigo.elemento = Elemento::Nenhum;

    jogador.barra = 0;

    log->clear();
    log->append(">> Que uma nova loucura começa!");

    btnFogo->setEnabled(true);
    btnAgua->setEnabled(true);
    btnTerra->setEnabled(true);
    btnVento->setEnabled(true);
    btnUlt->setEnabled(false);

    atualizarUI();
}


void Widget::mostrarAjuda()
{
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Ajuda - Magos Loucos");
    dialog->resize(520, 600);

    QTextEdit *texto = new QTextEdit(dialog);
    texto->setReadOnly(true);

    texto->setText(
        "=== REAÇÕES ELEMENTAIS ===\n\n"

        "🔥 + 💧 Vaporizar\n"
        "- Aumenta o ataque em 5\n\n"

        "🌱 + 🔥 Queimadura\n"
        "- Reduz a defesa do alvo em 5\n\n"

        "🌪️ + 🌱 Folhas Cortantes\n"
        "- O ataque ignora a defesa\n\n"

        "🔥 + 🌪️ Explosão\n"
        "- Reduz o ataque do alvo em 5\n\n"

        "💧 + 🌱 Lama\n"
        "- Cura o conjurador em 10 + 10% da vida perdida\n\n"

        "💧 + 🌪️ Névoa\n"
        "- Aumenta a defesa do conjurador em 5\n\n"

        "============================\n\n"

        "=== ULTIMATES ===\n\n"

        "☄️ Meteoro do Fulgor (60)\n"
        "- Causa 250% do ataque como dano\n"
        "- Aplica elemento Fogo\n\n"

        "🐉 Corrente do Leviatã (40)\n"
        "- Cura 30 + 20% da vida perdida\n"
        "- Remove o elemento aplicado em si\n\n"

        "⛰️ Terra Primordial (50)\n"
        "- Defesa +15 para si\n"
        "- Defesa -5 para o inimigo\n\n"

        "🌀️ Vendaval Uivante (70)\n"
        "- Causa 200% do ataque como dano\n"
        "- Aplica Vento\n"
        "- Se causar reação, mantém o elemento Vento\n\n"

        "🛰 Laser Orbital (100)\n"
        "- Causa 300% do ataque como dano verdadeiro\n"
        "- Ignora defesa\n\n"

        "💠 Zoltrak (30)\n"
        "- Causa 150% do ataque como dano\n"
        "- Aplica um efeito aleatório:\n"
        "  • +2 ATK (si mesmo)\n"
        "  • -2 ATK (alvo)\n"
        "  • +2 DEF (si mesmo)\n"
        "  • -2 DEF (alvo)\n"
        "  • Cura 5 + 5% da vida perdida\n"

        );

    QPushButton *fechar = new QPushButton("Fechar");
    connect(fechar, &QPushButton::clicked, dialog, &QDialog::accept);

    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(texto);
    layout->addWidget(fechar);

    dialog->exec();
}
