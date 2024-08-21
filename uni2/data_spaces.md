# Estruturas de Dados Espaciais

> Estudando algumas estruturas de dados usados em computação gráfica

## 📌 GRID

Básicamente A estrutura espacial **Grid**, divide o espaço em células de comprimento iguais, o que em 2d seria basicamente uma matriz, e em 3d uma grade cubica.

### ✅ Vantagens

- **Simplicidade**: A estrutura de grid é simples de implementar e entender, tornando-a uma escolha popular para muitas aplicações.
- **Desempenho**: Como o grid permite uma indexação direta por coordenadas, muitas operações, como busca e inserção, podem ser realizadas em tempo constante (O(1)) para cada célula.
- **Paralelismo**: A divisão regular do espaço facilita o paralelismo, onde diferentes células podem ser processadas independentemente, o que é útil em simulações massivamente paralelas.

### ❌ Desvantagens

- **Dependência do Tamanho da Célula**: A escolha do tamanho da célula é crítica. Se as células forem muito grandes, pode haver muitos objetos por célula, o que degrada a eficiência. Se forem muito pequenas, o número de células pode ser grande demais para ser gerenciado eficientemente.
- **Limitações em Ambientes Não Uniformes**: Em ambientes onde os objetos estão distribuídos de forma não uniforme, grids podem ser ineficientes, pois algumas células podem ficar vazias ou subutilizadas, enquanto outras podem se tornar congestionadas.

## 📌 ARVORE

estrutura de arvores dividem o espaço de forma recursiva até atingir alguma especificação delimitadora.

### ✅ Vantagens

- **Eficiência em Consultas Espaciais**: Melhora a velocidade de buscas e operações espaciais.

- **Redução de Complexidade Computacional**: Diminui o número de comparações necessárias.

- **Flexibilidade**: Adapta-se a diferentes tipos de dados e operações espaciais.

- **Escalabilidade**: Gerencia grandes volumes de dados de forma eficiente.

- **Uso Eficiente de Memória**: Armazena apenas as subdivisões do espaço relevantes.

### ❌ Desvantagens

- **Complexidade de Implementação**: Difícil de implementar corretamente.

- **Custo de Manutenção**: Requer esforço computacional para manter balanceada e atualizada.

- **Desempenho em Dados Desbalanceados**: Pode ser ineficiente com dados desbalanceados ou esparsos.

- **Problemas com Dimensionalidade**: Desempenho pode degradar em espaços de alta dimensão.

- **Sobrecarga de Rebalanceamento**: Pode exigir rebalanceamento frequente, adicionando sobrecarga.

## 📌 BOUNDING BOX

Uma Bounding Box é a menor caixa ou retângulo possível que pode conter completamente um objeto ou um conjunto de objetos no espaço.

### ✅ Vantagens

- **Simplicidade e Eficiência**: Fácil de implementar e rápida para realizar operações como interseção e colisão, sendo útil em tempo real.

- **Otimização**: Reduz a complexidade ao permitir filtragem preliminar, evitando cálculos desnecessários em objetos que não se sobrepõem.

- **Versatilidade**: Aplicável a uma ampla gama de problemas espaciais, independentemente da forma dos objetos.

### ❌ Desvantagens

- **Imprecisão**: Inclui espaço vazio ao redor dos objetos, o que pode levar a falsos positivos em colisões ou interseções.

- **Limitação de Orientação**: Para objetos rotacionados, as Bounding Boxes alinhadas aos eixos podem ser muito maiores do que o necessário.

- **Detalhamento Limitado**: Não captura detalhes internos dos objetos, exigindo métodos mais avançados para análises precisas.
