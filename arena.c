#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    double hp;
    double ataque, defesa;
    int vivo, nivel, stamina;
} Personagem;


double calcularDano(double ataque, double defesa)
{
    double danoHeroi = ataque - defesa;
    return danoHeroi;
}
int estaVivo(Personagem p)
{
    if (p.hp <= 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void inicializarHeroi(Personagem *heroi, char nome[])
{
    printf("Digite o nome do seu heroi: ");
    scanf(" %[^\n]", heroi->nome);


    heroi->hp = 100;
    heroi->ataque = 20;
    heroi->defesa = 10;
    heroi->vivo = 1;
    heroi->nivel = 1;
    heroi->stamina = 0;
    printf("\nNOME: %s\nATAQUE: %.2lf\nDEFESA: %.2lf\nNIVEL: %d\nSTAMINA: %d\n",heroi->nome,heroi->ataque * 2,heroi->defesa,heroi->nivel,heroi->stamina);

}
void inicializarInimigos(Personagem inimigos[], int quantidade)
{
    for(int i = 0; i < 3; i++)
    {
        inimigos[i].hp = (rand() % 41) + 40;
        inimigos[i].ataque = (rand() % 16 ) + 19;
        inimigos[i].defesa = (rand() % 11) + 5;
        inimigos[i].vivo = 1;
    }
}
double aumentarNivel(Personagem *h)
{
    h->ataque += 5;
    h->defesa += 5;
    h->nivel += 1;
    return h->ataque, h->defesa, h->nivel;

}
void exibirStatus(Personagem h, Personagem i)
{
    printf("\n--- STATUS ---\n");
    printf("%s: %.2lf HP\n", h.nome, h.hp);
    printf("Inimigo: %.2lf HP\n", i.hp);
    printf("--------------\n");
}



void batalhar(Personagem *heroi, Personagem *inimigo, int numero)
{
    int escolha, usos = 2, nivel = 1;
    double danoInimigo = 0, danoHeroi = 0;

    do
    {
        printf("\n1 = Defender\n2 = Ataque (toma o dobro de dano inimigo na rodada mas quebra a defesa inimiga)\n3 = Curar (recupera 15 HP, so pode usar 2 vezes)\nResposta: ");
        scanf("%d", &escolha);
        switch(escolha)
        {
        case 1:
            heroi->stamina ++;
            danoHeroi = 0;
            inimigo->hp -= danoHeroi;
            printf("\nVocê tem agora %d de stamina!\n", heroi->stamina);
            danoInimigo = calcularDano(inimigo->ataque, heroi->defesa);
            heroi->hp -= danoInimigo;

            break;

        case 2:
             if(heroi->stamina > 0)
                {
                    danoHeroi = calcularDano(heroi->ataque * 2, 0);
                    inimigo->hp -= danoHeroi;
                    heroi->stamina--;

                }
                else
                {
                    printf("VOCE NAO TEM STAMINA PARA ISSO\n");
                }
            if(inimigo->hp > 0)
            {
                danoInimigo = calcularDano(inimigo->ataque * 2, heroi->defesa);
                heroi->hp -= danoInimigo;
            }


            else{
                danoInimigo = 0;
            }

            break;
        case 3:
            if(usos > 0)
            {
                printf("\nVOCE GANHOU 15 DE HP\n");
                danoInimigo = calcularDano(inimigo->ataque, heroi->defesa);
                heroi->hp = heroi->hp + 15 - danoInimigo;
                danoHeroi = 0;
                usos--;
            }
            else
            {
                printf("\nACABOU AS SUAS CURAS\n");
                danoInimigo = calcularDano(inimigo->ataque, heroi->defesa);
                heroi->hp -= danoInimigo;
            }
            break;
        default:
            printf("\nopcao invalida\n");
            break;
        }

        if (heroi->hp <= 0)
        {

            heroi->vivo = estaVivo(*heroi);
            printf("VOCE RECEBEU %.2lf DE DANO\n", danoInimigo );
            printf("HEROI MORTO");
        }
        else if (inimigo->hp <= 0)
        {
            inimigo->vivo = estaVivo(*inimigo);
            printf("SEU ATAQUE FOI DE %.2lf DE DANO\n", danoHeroi);
            printf("VOCE RECEBEU %.2lf DE DANO\n", danoInimigo );
            printf("VIDA ATUAL = %.2lf\n", heroi->hp);
            printf("VIDA DO INIMIGO ATUAL: %.2lf\n",inimigo->hp);
            printf("\nPARABENS %s VOCE MATOU O INIMIGO %d\n", heroi->nome, numero);

        }
        else
        {
            printf("SEU ATAQUE FOI DE %.2lf DE DANO\n", danoHeroi);
            printf("VOCE RECEBEU %.2lf DE DANO\n", danoInimigo );
            printf("VIDA ATUAL = %.2lf\n", heroi->hp);
            printf("VIDA DO INIMIGO ATUAL: %.2lf\n",inimigo->hp);
        }
    }
    while(estaVivo(*heroi) == 1 && estaVivo(*inimigo) == 1);
}

int main()
{
    Personagem inimigo[3];
    Personagem heroi;
    int i, tutorial;
    char resto[60];

    do
    {
        printf("Deseja ler o tutorial curto antes de começar?\n1- sim\nqualquer outra tecla - nao\n resposta: ");
        scanf("%d", &tutorial);

    switch(tutorial){
    case 1:
        printf("\nBEM VINDO A ARENA DE BATALHA, SEU OBJETIVO EH PASSAR POR 3 INIMIGOS SEM MORRER, SERA QUE SEU HEROI SAIRA VIVO DESSA?\n");
        printf("A STAMINA EH NECESSARIA PARA ATACAR, SEM STAMINA VC ERRA SEU ATAQUE E RECEBE DANO. ALEM DISSO ELA EH ACUMULATIVA DURANTE TODOS OS ROUNDS E SO EH OBTIDA ATRAVES DA OPCAO DE DEFESA\n");
        break;
    default:
        tutorial = 2;
        gets(resto);
        break;
    }
    }while(tutorial != 1 && tutorial != 2);

    system("cls");

    inicializarHeroi(&heroi, heroi.nome);
    inicializarInimigos(&inimigo[0], 3);


    for(i = 0; i < 3; i++)
    {
        if (estaVivo(heroi) == 1 && estaVivo(inimigo[i]))
        {
            exibirStatus(heroi, inimigo[i]);
            batalhar(&heroi, &inimigo[i], i + 1);
            if(estaVivo(heroi) && i < 2)
            {
                aumentarNivel(&heroi);
                printf("\n--- VOCE SUBIU DE NIVEL ---");
                printf("\nATAQUE ATUAL: %.2lf", heroi.ataque * 2);
                printf("\nDEFESA ATUAL: %.2lf\n", heroi.defesa);
            }
            else if(estaVivo(heroi) && i == 2)
            {
                printf("\nVITORIA DO HEROI %s", heroi.nome);
            }

        }

    }
    return 0;
}
