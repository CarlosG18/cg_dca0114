# Shading

> Estudando os conceitos sobre shading em computação gráfica

## 🕵️‍♂️ O que é shading?

É a "tecnica" usada para definir como a superficie será retratada na cena, onde será definindo as cores e a influencia da luz, para se obter efeitos de sombra e iluminação. Algumas dessas técnicas são usadas de forma a reduzir o esforço computacional, usando o conceito de interpolações, por exemplo, para otimizar essa analise.

## 🧩 Algoritmos de Shading 

Existem alguns algoritmos para shading que são bastante usados no mundo da computação gráfica, os principais são:

### [1/3] 📌 Flat

A cor da superficie é definida a partir da cor obtida em um unico ponto. se calcula a cor e iluminação para um ponto da superficie, e para toda a superficie é atribuida esses parâmetros de cores e sombreamento.

### [2/3] 📌 Gouraud

O algoritmo de shading **"Gouraud"** é definido da seguinte forma: é calculado a cor dos verticies do poligono, logo em seguida, a cor da superficie será a interpolação das cores dos verticies, que é feita de forma linear, garantindo uma suavização da cor final na superficie. 

### [3/3] 📌 Phong

O **"Phong"** é similar ao **"Gouraud"**, porém é calculado as normais dos verticies, e é feito a interpolação dessas normais afim de definir a cor da superficie para cada pixel.
