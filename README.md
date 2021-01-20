# 


# neural-network-base

This is a base for a Neural Network in C++, with feedforwarding but no backpropagation

## Installation

You can just import this class in your program and use it as you will. There are comments inside as to how to use, but it follows basic class usage.

## Usage

First you need an array of doubles (that will be your input), a double for bias in the neuron and a double for bias in the output

```double _inputs[] = {6,7};
	double _biasNeuron = 0;
	double _biasOutput = 0;
```

Then you can initialize the class with those variables.

```RedeNeural n(_inputs, _biasNeuron, _biasOutput);
```

And so the output is fed, you use the feedForward function.

```n.feedForward();
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)
