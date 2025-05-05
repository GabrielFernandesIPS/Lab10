# Algoritmos e Tipos Abstratos de Dados

## Lab 10 - Sistema de Votação

Este repositório foi criado a partir de:

* [https://github.com/estsetubal-atad/CProgram\_Template](https://github.com/estsetubal-atad/CProgram_Template)

Consulte o README se tiver dúvidas sobre a sua utilização.

---

**Objetivos**:

* Utilização do ADT Map para implementar um sistema simples de votação.
* Exploração de operações como inserção, procura, atualização e iteração sobre pares chave/valor.

**Referências**:

* “Tipos Abstratos de Dados – Linguagem C. Bruno Silva”, disponível no Moodle.

---

### Sistema de Votação

Pretende-se desenvolver uma aplicação de consola que permita gerir uma votação simples. Cada candidato é identificado por um nome (contido numa instância de `StringWrap`) e está associado a um número de votos (`int`).

A aplicação deve suportar as seguintes funcionalidades principais (exemplo de execução no final do enunciado):

* Abertura de uma nova votação com lista de candidatos.
* Registo de votos para candidatos existentes.
* Encerramento da votação.
* Listagem dos candidatos e respetivas contagens.
* Determinação do vencedor.
* Apresentação de resultados ordenados por número de votos (decrescente).

Para armazenar os candidatos e respetivas contagens de votos, deve ser utilizado o **ADT Map** fornecido.

### 1 | Análise de código

1. Analise a estrutura do código fornecido. 
2. Verifique a estrutura do `main`. Toda a lógica a desenvolver está contida, de momento, neste ficheiro.

### 2 | Parameterização do ADT Map

3. Faça a parameterização dos tipos de chave e valor do `ADT Map` para este projeto.
	- `MapKey` deverá ser do tipo `StringWrap` (para guardar texto - nome de candidato);
	- `MapValue` deverá ser do tipo `int` (para guardar o número de votos).

4. Verifique a correta compilação do programa.

### 3 | Funcionamento básico

5. Teste a estrutura de menu, sabendo que muita da lógica ainda não está implementada.

6. Implemente o código em falta de acordo com os comentários `TODO`. 
	- :warning: Tudo o que forem listagens, podem ser feitas de forma "simplificada" de momento, e.g., sem nenhum tipo de ordenação.

### 4 | Refinamento

7. Apresente as listagens de acordo com as ordenações solicitadas

### 5 | Organização de funções

8. Melhore a legibilidade do código, criando e invocando funções para tarefas específicas, e.g., popular candidatos, determinar vencedor, listar candidatos, etc.

### Exemplo de Execução

```
--- Sistema de Votação ---
1. Abrir nova votação
2. Registar voto
3. Fechar votação
4. Listar candidatos (ordem alfabética)
5. Apresentar vencedor
6. Resultados por número de votos
0. Sair

Opção: 1
Registo de candidatos ->
Nome (ENTER para terminar)?: Elisa
Nome (ENTER para terminar)?: Carlos
Nome (ENTER para terminar)?: Bruno
Nome (ENTER para terminar)?: 
[INFO] Nova votação iniciada.

Opção: 2
Nome do candidato: Bruno
[VOTO REGISTADO]

Opção: 2
Nome do candidato: Elisa
[VOTO REGISTADO]

Opção: 2
Nome do candidato: Bruno
[VOTO REGISTADO]

Opção: 2
Nome do candidato: Daniel
[CANDIDATO INEXISTENTE]

Opção: 4
Candidatos:
- Bruno
- Carlos
- Elisa

Opção: 6
Resultados:
1º Bruno - 2 votos
2º Elisa - 1 voto
3º Carlos - 0 votos

Opção: 5
Vencedor: Bruno

Opção: 3
[INFO] Votação encerrada.

Opção: 2
[ERRO] A votação está encerrada. Não é possível registar mais votos.

Opção: 0
[PROGRAMA TERMINADO]
```
---

[bruno.silva@estsetubal.ips.pt](mailto:bruno.silva@estsetubal.ips.pt)
