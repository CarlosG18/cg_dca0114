# Problema da visibilidade

> Estudando os conceitos e algoritimos de visibilidade em computação gráfica

## ❗ Definindo o problema de visibilidade

O problema da visibilidade se definine na dificuldade de saber qual elemento deve ser apresentado na imagem final, a partir de uma cena que possui vários elementos. como saber qual elemento deve ser mostrado se outro estiver na frente dele analisando em um certo ponto de vista? para solucionar esse problema temos alguns algoritmos:

## 🧩 algoritimos de visibilidade

Temos algumas formas de obter uma solução sem disperdiçar tanto recursos computacionais:

### [1/4] 📌 Z-buffer

#### 🔍 Como Funciona?

Este algoritimo de visualização funciona com um buffer que guarda a profundidade (z) de cada pixel. quando iniciado, o valor do z-buffer é atribuido com o valor máximo para a profundidade (representando o infinito) em todos os pixels. a cada triangulo da cena, se o valor de profundidade do pixel atual for menor (mais próximo da câmera) do que o valor armazenado no z-buffer, o pixel é considerado visível:
 - O valor de profundidade no z-buffer é atualizado com o novo valor.
 - A cor do pixel é escrita no framebuffer.
 
Se o valor de profundidade do pixel atual for maior (mais distante da câmera), o pixel é descartado e não é renderizado.

#### ✅ Vantagens

- **Simples de Implementar**: O algoritmo é relativamente simples e direto, facilitando sua implementação em hardware e software.

- **Eficiência**: Permite a renderização de cenas complexas com muitos polígonos de maneira eficiente, pois apenas os pixels visíveis são desenhados.

- **Independência da Ordem dos Polígonos**: Não é necessário ordenar os polígonos antes da renderização.

#### ❌ Desvantagens

- **Uso de Memória**: Requer memória adicional para armazenar o z-buffer, o que pode ser significativo para telas de alta resolução.

- **Problemas de Precisão**: Pode sofrer com problemas de precisão devido à limitação de bits usados para representar valores de profundidade, levando a artefatos conhecidos como "z-fighting" quando dois polígonos têm profundidades muito próximas.

- **Desempenho Dependente de Resolução**: O desempenho pode diminuir em resoluções mais altas devido ao aumento no número de pixels que precisam ser processados.

#### 📝 Pseudo código

```
// Inicialização
Para cada pixel na tela:
    z-buffer[pixel] = valor máximo (por exemplo, infinito)
    framebuffer[pixel] = cor de fundo

// Renderização de cada triângulo
Para cada triângulo na cena:
    Para cada pixel dentro do triângulo:
        z = calcular_profundidade_do_pixel(triangle, pixel)

        Se z < z-buffer[pixel]:
            z-buffer[pixel] = z
            framebuffer[pixel] = calcular_cor_do_pixel(triangle, pixel)
        Fim Se
    Fim Para
Fim Para
```

### [2/4] 📌 Pintor

#### 🔍 Como Funciona?

#### ✅ Vantagens

#### ❌ Desvantagens

### [3/4] 📌 Ray Casting
#### 🔍 Como Funciona?

#### ✅ Vantagens

#### ❌ Desvantagens

### [4/4] 📌 Ray Tracing

#### 🔍 Como Funciona?

#### ✅ Vantagens

#### ❌ Desvantagens
