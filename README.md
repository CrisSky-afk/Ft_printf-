# 🖨️ ft_printf

Implementação do projeto **ft_printf** da Escola 42, desenvolvida em **C**, com o objetivo de recriar parte do comportamento da função `printf()` da biblioteca padrão do C.

Este projeto aprofunda conceitos fundamentais como **funções variádicas**, manipulação de argumentos, conversão de tipos e controle preciso da saída para o terminal.

---

## 📖 Sobre o projeto

A função `printf()` é uma das funções mais utilizadas da linguagem C. Ela permite imprimir diferentes tipos de dados utilizando especificadores de formato.

O desafio deste projeto consiste em implementar uma versão própria dessa função, respeitando o comportamento da original para os formatos exigidos pelo subject.

---

## 🎯 Objetivos

- Compreender o funcionamento de funções variádicas;
- Utilizar a biblioteca `<stdarg.h>`;
- Manipular diferentes tipos de dados;
- Trabalhar com conversões numéricas;
- Desenvolver uma biblioteca reutilizável;
- Reproduzir o comportamento da `printf` original.

---

# ⚙️ Protótipo

```c
int	ft_printf(const char *format, ...);
```

A função retorna:

- O número total de caracteres impressos;
- `-1` em caso de erro de escrita.

---

# ✨ Conversões implementadas

| Conversão | Descrição |
|-----------|------------|
| `%c` | Caractere |
| `%s` | String |
| `%p` | Ponteiro |
| `%d` | Inteiro decimal com sinal |
| `%i` | Inteiro decimal |
| `%u` | Inteiro decimal sem sinal |
| `%x` | Hexadecimal minúsculo |
| `%X` | Hexadecimal maiúsculo |
| `%%` | Imprime o caractere `%` |

---

# 🏗️ Estrutura do projeto

```text
.
├── Makefile
├── ft_printf.h
├── ft_printf.c
├── ft_function.c
├── ft_functions.c
└── libftprintf.a
```

---

# 📂 Descrição dos arquivos

### `ft_printf.c`

Responsável pela função principal.

- Percorre a string de formato;
- Identifica os especificadores;
- Recupera os argumentos variádicos;
- Direciona cada conversão para sua função correspondente.

---

### `ft_function.c`

Implementa parte das funções auxiliares utilizadas pelas conversões.

Exemplos:

- Impressão de caracteres;
- Impressão de strings;
- Conversões numéricas.

---

### `ft_functions.c`

Implementa funções complementares responsáveis pelas demais conversões e tratamento dos formatos suportados.

---

### `ft_printf.h`

Contém:

- Protótipos;
- Inclusões necessárias;
- Definições utilizadas pela biblioteca.

---

# ⚙️ Compilação

Compile a biblioteca utilizando:

```bash
make
```

Biblioteca gerada:

```text
libftprintf.a
```

---

# 🧹 Regras do Makefile

### Compilar

```bash
make
```

---

### Remover objetos

```bash
make clean
```

---

### Remover objetos e biblioteca

```bash
make fclean
```

---

### Recompilar tudo

```bash
make re
```

---

# ▶️ Como utilizar

Após compilar:

```bash
make
```

Inclua o cabeçalho:

```c
#include "ft_printf.h"
```

E utilize normalmente:

```c
ft_printf("Olá, mundo!\n");
ft_printf("Número: %d\n", 42);
ft_printf("Hexadecimal: %x\n", 255);
```

---

# 💻 Exemplos

## Caracteres

```c
ft_printf("Char: %c\n", 'A');
```

Saída:

```text
Char: A
```

---

## Strings

```c
ft_printf("String: %s\n", "Bom dia com b de bacana");
```

Saída:

```text
String: Bom dia com b de bacana
```

---

## Inteiros

```c
ft_printf("Inteiro: %d\n", -86);
ft_printf("Decimal: %i\n", 344);
```

Saída:

```text
Inteiro: -86
Decimal: 344
```

---

## Unsigned

```c
ft_printf("Unsigned: %u\n", 3535);
```

Saída:

```text
Unsigned: 3535
```

---

## Hexadecimal

```c
ft_printf("Hexadecimal minúsculo: %x\n", 63265719);
ft_printf("Hexadecimal maiúsculo: %X\n", 63265719);
```

Saída:

```text
Hexadecimal minúsculo: 3c55c77
Hexadecimal maiúsculo: 3C55C77
```

---

## Percentual

```c
ft_printf("Sinal de porcentagem: %%\n");
```

Saída:

```text
Sinal de porcentagem: %
```

---

## Ponteiros

```c
int n = 42;

ft_printf("Ponteiro: %p\n", &n);
```

Saída (exemplo):

```text
Ponteiro: 0x7ffd3e0d8c4c
```

---

# 🧠 Funcionamento

A função percorre a string de formato caractere por caractere.

Quando encontra `%`, identifica o especificador correspondente e chama a função responsável pela conversão.

Fluxo simplificado:

```text
Recebe format
      ↓
Percorre a string
      ↓
Encontra '%'
      ↓
Identifica especificador
      ↓
Obtém argumento com va_arg
      ↓
Converte o valor
      ↓
Imprime
      ↓
Atualiza contador
      ↓
Retorna total de caracteres
```

---

# 🔄 Fluxo da execução

```text
ft_printf()
     ↓
va_start()
     ↓
Leitura do format
     ↓
Conversão adequada
     ↓
write()
     ↓
Contabilização dos caracteres
     ↓
va_end()
     ↓
Retorno
```

---

# 🧪 Testes realizados

- ✅ `%c`
- ✅ `%s`
- ✅ `%p`
- ✅ `%d`
- ✅ `%i`
- ✅ `%u`
- ✅ `%x`
- ✅ `%X`
- ✅ `%%`
- ✅ Comparação com a `printf` original;
- ✅ Verificação do valor de retorno;
- ✅ Testes com `NULL`;
- ✅ Testes com `INT_MIN` e `INT_MAX`;
- ✅ Testes com `UINT_MAX`;
- ✅ Valgrind sem vazamentos de memória.

---

# 🔐 Tratamento de casos especiais

A implementação contempla situações como:

- Strings nulas (`NULL`);
- Inteiros negativos;
- Valores extremos;
- Impressão correta do caractere `%`;
- Conversão de ponteiros.

---

# 📚 Conceitos estudados

Durante o desenvolvimento deste projeto foram explorados conceitos como:

- Funções variádicas;
- `stdarg.h`;
- `va_start`;
- `va_arg`;
- `va_end`;
- Conversão de bases numéricas;
- Escrita utilizando `write()`;
- Organização modular de código.

---

# 🛠️ Tecnologias utilizadas

- Linguagem C;
- GNU Make;
- Biblioteca `stdarg.h`;
- Função `write()`;
- Valgrind.

---

# 👩‍💻 Autoria

Projeto desenvolvido como parte do currículo da **42**.

Autora:

- **Cristiane Suominsky** (`csuomins` / `cris_sky`)

---

> *"Por trás de cada simples printf existe uma pequena aula sobre como a linguagem C realmente funciona."* 🖨️
