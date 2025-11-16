# Conversor de Base Numérica

**Informações do Projeto:**
- **Curso:** Ciência da Computação - Algoritmos 1
- **Instituição:** FAM (Faculdade de Americana)
- **Tipo:** Projeto Acadêmico

## Visão Geral do Projeto

Esta é uma aplicação baseada em console que converte números decimais para diferentes bases numéricas (Binário, Octal e Hexadecimal). O programa utiliza um sistema de navegação orientado por menus para fornecer uma experiência interativa ao usuário.

## Arquitetura do Sistema

### Componentes Principais

1. **Sistema de Controle de Menu**
   - Gerenciamento centralizado de menus
   - Registro e navegação de menus
   - Invocação dinâmica de menus

2. **Módulo de Processamento**
   - Coleta de entrada de números
   - Seleção de conversão de base
   - Execução de conversão

3. **Módulo de Histórico**
   - Armazena ciclos de processamento
   - Exibe histórico de conversões
   - Rastreia múltiplas sessões de processamento

4. **Sistema de Cache**
   - Armazena dados de processamento
   - Gerencia histórico de conversões
   - Mantém até 40 ciclos de processamento

## Fluxo do Programa

### Inicialização
1. O programa inicia em `main()`
2. Registra todos os menus (Principal, Processamento, Histórico, Participantes)
3. Invoca o Menu Principal

### Fluxo do Menu Principal
- Exibe opções disponíveis
- Usuário seleciona uma opção (1-3) ou sai (0)
- Roteia para o menu selecionado ou encerra o programa

### Fluxo de Processamento
1. Usuário especifica a quantidade de números a inserir
2. Usuário insere números decimais (validados)
3. Usuário seleciona o tipo de conversão (Binário/Octal/Hexadecimal)
4. Sistema converte todos os números
5. Ordena os resultados em ordem crescente, a partir da vírgula decimal.
6. Resultados são exibidos
7. Usuário retorna ao menu principal

### Fluxo de Histórico
- Exibe todos os ciclos de processamento anteriores
- Mostra conversões com seus tipos
- Usuário pode retornar ao menu principal

### Fluxo de Participantes
- Exibe informações dos membros do grupo
- Usuário retorna ao menu principal

## Características Principais

- **Validação de Entrada:** Garante que apenas números positivos sejam aceitos
- **Múltiplas Conversões:** Suporta Binário, Octal e Hexadecimal
- **Rastreamento de Histórico:** Mantém registros de todas as conversões
- **Navegação por Menu:** Sistema de menu intuitivo com funcionalidade de "voltar"
- **Tratamento de Erros:** Valida entrada do usuário e fornece feedback

## Estruturas de Dados

- **MenuStruct:** Contém nome do menu, ponteiro de método e identificador de escolha
- **ProcessingData:** Armazena números de entrada, resultados convertidos e tipo de conversão
- **ConversionType:** Enumeração para Binário, Octal e Hexadecimal

## Algoritmos de Conversão

Todas as conversões usam o método de divisão:
- **Binário:** Divide por 2, coleta restos
- **Octal:** Divide por 8, coleta restos
- **Hexadecimal:** Divide por 16, coleta restos (0-9, A-F)

Os restos são coletados em ordem reversa para formar o resultado final.
