# ⚔️ Arena de Batalha
 
Jogo de batalha por turnos desenvolvido em linguagem C, criado como projeto final do curso de lógica de programação.
 
---
 
## 📖 Sobre o Projeto
 
O jogador cria um herói e enfrenta 3 inimigos em sequência numa arena de batalha. Cada vitória concede experiência e evolução ao herói. O objetivo é sobreviver aos 3 confrontos.
 
O projeto foi desenvolvido do zero com foco em aplicar os principais conceitos da linguagem C: structs, ponteiros, funções, procedimentos, vetores e estruturas de controle.
 
---
 
## 🎮 Como Jogar
 
**1. Clone o repositório**
```bash
git clone https://github.com/seu-usuario/arena-de-batalha.git
```
 
**2. Compile o código**
```bash
gcc arena.c -o arena
```
 
**3. Execute**
```bash
./arena
```
 
---
 
## ⚙️ Mecânicas do Jogo
 
### Ações por turno
| Opção | Ação | Efeito |
|-------|------|--------|
| 1 | Defender | Ganha 1 de stamina, recebe dano normalmente |
| 2 | Super Ataque | Gasta 1 stamina, ataca com dano dobrado, recebe dano dobrado |
| 3 | Curar | Recupera 15 HP e recebe dano do inimigo (2 usos por batalha) |
 
### Sistema de Stamina
- A stamina é acumulada usando a opção de **Defender**
- Sem stamina, o Super Ataque falha e o herói ainda recebe dano
- A stamina persiste entre batalhas
 
### Progressão
- Ao vencer cada inimigo, o herói **sobe de nível**
- Cada nível concede **+5 de ataque** e **+5 de defesa**
 
### Inimigos
- Cada inimigo tem atributos gerados **aleatoriamente**
- HP: 40 a 80 | Ataque: 19 a 34 | Defesa: 5 a 15
 
---
 
## 🧠 Conceitos Aplicados
 
- `struct` — modelagem do personagem com todos os atributos
- Ponteiros — passagem por referência nas funções
- Vetores — array de inimigos
- Funções com retorno — `calcularDano`, `estaVivo`, `aumentarNivel`
- Procedimentos `void` — `inicializarHeroi`, `inicializarInimigos`, `exibirStatus`, `batalhar`
- `switch / case` — menu de ações
- `do...while` e `for` — loop de turnos e de batalhas
- `rand()` — geração aleatória dos atributos dos inimigos
 
---
 
## 📁 Estrutura do Projeto
 
```
arena-de-batalha/
└── arena.c       # Código fonte principal
└── README.md     # Este arquivo
```
 
---
 
## 👨‍💻 Autor
 
Feito com dedicação como projeto final do curso de linguagem C.
