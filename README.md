# neural-network-base

Esta é uma base para uma rede neural em C ++, com feedforwarding, mas sem backpropagation. Também há uma pequena imagem com uma visualização dos valores internos de uma rede neural genérica.

## Installation

Você pode simplesmente importar esta classe em seu programa e usá-la como quiser. Há comentários internos sobre como usar, mas segue o uso básico da classe.

## Usage

Primeiro você precisa de uma matriz de doubles (que será sua entrada), um double para viés no neurônio e um double para viés na saída

```c
	double _inputs[] = {6,7};
	double _biasNeuron = 0;
	double _biasOutput = 0;
```

Então você pode inicializar a classe com essas variáveis.

```c
	RedeNeural n(_inputs, _biasNeuron, _biasOutput);
```

E para que a saída seja alimentada, você usa a função feedForward.

```c
	n.feedForward();
```

Inicialmente a rede neural possui 2 inputs, 4 neurons e 2 outputs. Para alterar isso, basta ir no código e mudar as constantes específicas.

```c
	#define N_INPUTS 2
	#define N_NEURONS 4
	#define N_OUTPUTS 2
```

Os axons também estão restritos por MIN e MAX. Mudar esses valores também segue a mesma lógica, eles começam limitados entre -1 e 1.

```c
	#define MIN_AXON -1
	#define MAX_AXON 1
	//#define ESCOPO_DECIMAL_AXON 100
```

Obs.: O limite de escopo decimal foi desabilitado por padrão. Os doubles estão ilimitados. Caso queira limitar as casas decimais, descomente as linhas apropriadas.

## Contributing
Pull requests são bem-vindos. Para mudanças importantes, abra um problema primeiro para discutir o que você gostaria de mudar.

Certifique-se de atualizar os testes conforme apropriado.

## License
[MIT](https://choosealicense.com/licenses/mit/)
