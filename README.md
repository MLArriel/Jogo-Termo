<div align="center">

# TERMO

Projeto desenvolvido para a disciplina **Introdução a Sistemas Computacionais** da Universidade de São Paulo.

---

Uma adaptação do clássico Wordle desenvolvida em Assembly para o Processador ICMC

</div>

---

Maria Luisa Arriel

Maria Eduarda Aissa

</div>

---

## Sobre o projeto

**TERMO** é uma recriação do famoso jogo de adivinhação de palavras **Wordle**, totalmente implementada em **Assembly** para o **Processador ICMC**.

O projeto foi desenvolvido sem o auxílio de bibliotecas gráficas, motores de jogo ou recursos externos. Toda a interface, lógica, controle de memória, manipulação de entrada e saída e gerenciamento do estado da partida foram implementados diretamente em linguagem Assembly.

Além da mecânica principal do jogo, foram adicionadas diversas melhorias visuais e funcionais para proporcionar uma experiência mais agradável ao usuário.

---

## Objetivo

Descobrir uma palavra secreta de **cinco letras** em até **seis tentativas**.

Após cada tentativa, o jogo informa quais letras:

- pertencem à palavra e estão na posição correta;
- pertencem à palavra, mas estão na posição errada;
- não fazem parte da palavra.

Ao final da partida, o jogador pode iniciar uma nova rodada imediatamente.

---

# Funcionalidades

- Banco com **172 palavras** cuidadosamente selecionadas.
- Escolha pseudoaleatória da palavra secreta.
- Sistema completo de leitura do teclado.
- Validação de entrada.
- Comparação letra por letra.
- Controle das seis tentativas.
- Feedback utilizando três cores.
- Tela inicial personalizada.
- Tela de vitória personalizada.
- Tela de derrota personalizada.
- Exibição da palavra correta quando o jogador perde.
- Sistema de reinício sem necessidade de reiniciar o simulador.
- Caracteres personalizados através da edição do **charmap.mif**.
- Interface inteiramente construída utilizando a memória de vídeo do Processador ICMC.

---

# Regras

- Todas as palavras possuem exatamente **cinco letras**.
- Palavras originalmente acentuadas são utilizadas **sem acentos**.
- O banco de palavras não contém letras repetidas.
- Cada partida possui no máximo **cinco tentativas**.

---

# Estrutura do projeto

```
.
├── termo.asm
├── charmap.mif
└── README.md
```

### termo.asm

Arquivo principal contendo toda a lógica do jogo.

### charmap.mif

Mapa de caracteres personalizado utilizado para melhorar a interface gráfica.

### README.md

Documentação do projeto.


---

# Organização do código

O código foi dividido em módulos independentes, facilitando a leitura, manutenção e reutilização.

```
Inicialização

├── Tela inicial
├── Seleção da palavra
├── Entrada do jogador
├── Comparação das letras
├── Atualização da interface
├── Controle de tentativas
├── Vitória
├── Derrota
└── Reinício da partida
```

---

# Conceitos utilizados

Durante o desenvolvimento foram aplicados diversos conceitos da arquitetura de computadores, como:

- registradores;
- pilha (`push` e `pop`);
- sub-rotinas;
- manipulação de memória;
- entrada e saída;
- desvios condicionais;
- comparação de caracteres;
- geração pseudoaleatória;
- modularização de código;
- gerenciamento do fluxo de execução.

---

# Interface

O jogo utiliza uma interface inteiramente construída em Assembly.

Entre as personalizações implementadas estão:

- novo conjunto de caracteres através do `charmap`;
- telas personalizadas de início, vitória e derrota;
- elementos gráficos desenhados em ASCII Art;
- feedback visual por cores;
- organização da interface inspirada no jogo original TERMO.

---

# Banco de palavras

O jogo utiliza um banco contendo **172 palavras**.

Os critérios utilizados para a seleção foram:

- cinco letras;
- palavras da língua portuguesa;
- ausência de acentos;
- ausência de cedilha;
- ausência de caracteres especiais;
- ausência de letras repetidas.

---

# Como executar

1. Abra o Simulador do Processador ICMC.
2. Carregue o arquivo `termo.asm`.
3. Utilize o `charmap.mif` personalizado.
4. Monte o programa.
5. Execute a simulação.
6. Pressione **ENTER** para iniciar.

---

# Possíveis melhorias

O projeto foi desenvolvido de forma modular para facilitar futuras expansões, como:

- diferentes níveis de dificuldade;
- animações;
- sistema de pontuação;
- cronômetro;
- estatísticas de partidas;
- ranking;
- banco de palavras expandido;
- efeitos sonoros.

---

# Aprendizados

O desenvolvimento deste projeto permitiu aplicar, na prática, diversos conceitos estudados durante a disciplina, especialmente relacionados à programação de baixo nível.

Além da implementação da lógica do jogo, o projeto exigiu atenção ao gerenciamento de memória, manipulação de registradores, organização modular do código e construção manual de toda a interface gráfica.

---

# Créditos

Projeto desenvolvido para a disciplina **Introdução a Sistemas Computacionais**.

Inspirado no jogo **TERMO (Wordle)** e adaptado para execução no **Processador ICMC**.

---

<div align="center">

Desenvolvido em Assembly.
Link com vídeo explicativo: https://youtu.be/37iL_YUWYfQ



</div>
