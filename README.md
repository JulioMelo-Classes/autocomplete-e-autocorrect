### Sumário
- [💻 Introdução](#-introdução)
  - [Autocomplete](#autocomplete)
  - [Autocorrect](#autocorrect)
- [⚙️ Requisitos](#️-requisitos)
    - [Ambiente](#ambiente)
    - [Linguagem de programação](#linguagem-de-programação)
    - [Requisítos de compilação](#requisítos-de-compilação)
  - [Como rodar](#como-rodar)
- [💽 Base de dados](#-base-de-dados)
- [🧪 Validações e testes](#-validações-e-testes)
    - [Verificação de caracteres especiais](#verificação-de-caracteres-especiais)
    - [Verificação de peso negativo](#verificação-de-peso-negativo)
    - [Verificação de palavra vazia](#verificação-de-palavra-vazia)
    - [Verificação de peso vazio](#verificação-de-peso-vazio)
    - [Verificação caso o arquivo não exista](#verificação-caso-o-arquivo-não-exista)
- [🤝 Colaboradores](#-colaboradores)
- [🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧](#)
***
</br>

# 💻 Introdução
## Autocomplete
 * O **preenchimento automático**, também conhecido como sugestão automática ou sugestão de pesquisa, é um recurso que fornece previsões à medida que você digita em uma caixa de texto. É comumente associado a motores de busca, embora possa ser usado para outros fins também.

<p align="center">
    <img src="https://user-images.githubusercontent.com/71523376/173905176-3a6013a6-ddc8-49a8-bb4b-d38fb5def467.png" width="500">
</p>

## Autocorrect
 * A **autocorreção**, também conhecida como substituição de texto, é uma função de correção automática de dados comumente encontrada em processadores de texto e interfaces de edição de texto para smartphones e tablets.
<p align="center">
    <img src="https://i0.wp.com/www.alphr.com/wp-content/uploads/2017/07/spellingmistake-1.jpg?resize=640%2C320&ssl=1" width="500">
</p>
</br>

# ⚙️ Requisitos

### Ambiente
  * Linux</br>
      <img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" width="140" height="50"/>

### Linguagem de programação
  * C++</br>
    <img src="https://img.shields.io/badge/-C++%20-00599C?logo=c%2B%2B&style=for-the-badge" width="140" height="50"/>

### Requisítos de compilação
  * CMAKE</br>
    <img src="https://img.shields.io/badge/CMake-%23008FBA.svg?style=for-the-badge&logo=cmake&logoColor=white" width="140" height="50" alt="CMAKE"/>
  * GCC</br>
    <img src="https://img.shields.io/badge/-GCC %20-A42E2B?logo=gnu&style=for-the-badge" width="140" height="50" alt="GCC"/>
***
## Como rodar
   - ### Para rodar o programa utilize os comandos no terminal na pasta raíz do projeto:
  &emsp; &emsp; 👇
  1. ```
      mkdir build
     ```
  2. ```
      cd build
     ```
  3. ```
      cmake ..
     ```
  4. ```
      cmake --build .
     ```
  5. ```
      ./words_complete_correct ../data/wikitionary.txt
     ```
     ou

  -  ```
      ../assets/run.sh
     ```
  &emsp; &emsp; 👆
</br>

</br>

# 💽 Base de dados
Foi usado uma base de dados com quase 10.000 palavras em inglês fazendo pares com um número que representa a "frequência" dela no vocabulário.
* Na base de dados utlizada foram retirados os caracteres especiais.
* Transformado todas as letras para minúsculo.
* Feito um tratamento dos espaços entre o **número** e **palavra**. </br>

Também houve algumas poucas remoções de linhas diretamente no arquivo.
>*O script utilizado está na pasta "data".*

</br>

# 🧪 Validações e testes
Testes para verificar se a base de dados está em conformidade para ser utilizada pelo programa.</br>
<i>Utilize os comandos abaixo no terminal.</i>

### Verificação de caracteres especiais
  - ```
    ./words_complete_correct ../data/testes/teste_caractere.txt
    ```
  - Saída esperada **`Erro! Caractere inválido & na linha 2.`**

</br>

### Verificação de peso negativo
  - ```
    ./words_complete_correct ../data/testes/teste_negativo.txt
    ```
  - Saída esperada **`Erro! Peso negativo na linha 3.`**

</br>

### Verificação de palavra vazia
  - ```
    ./words_complete_correct ../data/testes/teste_vazio.txt
    ```
  - Saída esperada **`Erro! Palavra vazia na linha 4.`**

</br>

### Verificação de peso vazio
  - ```
    ./words_complete_correct ../data/testes/teste_peso_vazio.txt
    ```
  - Saída esperada **`Erro! Peso vazio na linha 3.`**

</br>

### Verificação caso o arquivo não exista
  - ```
    ./words_complete_correct ../data/testes/teste_inexistente.txt
    ```
  - Saída esperada **`Erro! Arquivo inexistente.`**

</br>

# 🤝 Colaboradores
  * [Danrley Lima](https://github.com/Danrley-Lima)
  * [Lucas Morais](https://github.com/lucas-morais27)
  
***
# 🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧🚧
