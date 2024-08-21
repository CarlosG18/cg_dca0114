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

O algoritmo de visibilidade do pintor como o nome já sugere, se baseia em como um pintor real faz suas pinturas. Primeiramente é feito a pintura do fundo e depois sobreescrevendo esse fundo com os objetos que vem logo em seguida.

#### 🔍 Como Funciona?

Para o funcionamento do algoritmo precisamos obter todos os poligonos da cena e ordenalos em função da distância que esse poligono está na cena, essa ordenação será feita de maneira a deixar os poligonos mais distantes da cena nas primeiras posições para serem pintados primeiro. a medida em que esses poligonos vão sendo pintados, os elementos que estão mais proximos da camera serão representados a frente dos elementos que estão mais distantes.

#### ✅ Vantagens

- **Simplicidade**: O algoritmo é relativamente fácil de entender e implementar.

- **Flexibilidade**: Pode ser usado com qualquer tipo de primitiva gráfica.

#### ❌ Desvantagens

- **Eneficiência com Polígonos Intersectados**: A necessidade de dividir polígonos intersectados pode ser complexa e custosa.

- **Ordenação Dinâmica**: Em cenas complexas, a reordenação dinâmica dos polígonos pode ser computacionalmente intensiva.

- **Performance**: Não é o método mais eficiente para cenas complexas ou com muitos polígonos, onde algoritmos como o Z-buffer são preferíveis.

#### 📝 Pseudo código

```
    dados:
        vetor_de_poligonos;
        poligonos;

    para poligono no poligonos:
        calcule sua profundidade na cena
        adicione em ordem no vetor_de_poligonos em relação a profundidade

    para poligono no vetor_de_poligonos:
        desenhe o poligono
```

### [3/4] 📌 Ray Casting

O Ray casting é um algoritimo de visibilidade que usa raios para calcular os parâmetros dos pixels na cena.

#### 🔍 Como Funciona?

Basicamente o Ray Casting funciona da seguinte maneira: são projetados "raios" que partem geralmente da câmera ou de um ponto de vista, em direção a cena. Após isso será verificado onde o raio foi intersectado na cena, caso o objeto seja intersectado, será calculado o ponto onde foi intersectado e o vetor normal a superficie. com essas informações básicas será possivel calcular todos os parâmetros do pixel, como iluminação, cor entre outros.

#### ✅ Vantagens

- **Simplicidade**: Fácil de implementar e entender.

- **Qualidade visual**: Gera imagens realistas com sombras e reflexos precisos.

- **Versatilidade**: Pode ser usado em diferentes tipos de cenas e iluminações.

#### ❌ Desvantagens

- **Desempenho**: Pode ser lento, pois verifica a interseção de raios com todos os objetos da cena.

- **Requer muito poder computacional**: Processamento intensivo, especialmente em cenas complexas.

- **Limitado para cenas dinâmicas**: Não é ideal para cenas em tempo real, como jogos, devido à sua lentidão.

#### 📝 Pseudo código

```
    INICIALIZAR câmera e cena

    PARA cada pixel (x, y) na tela:
        raio = calcularRaio(camera, x, y)
        cor_pixel = corFundo
    
    PARA cada objeto na cena:
        se intersecionar(raio, objeto):
            cor_pixel = calcularCor(raio, objeto, luzes)
            interromper (se a cena não tiver transparência)

    definirCorPixel(x, y, cor_pixel)

renderizarImagem()
```