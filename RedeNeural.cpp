// Leonardo Antonetti da Motta - ICMC USP 11275338
// POR ALGUM MOTIVO, O OUTPUT FICA COMO nan SE VC NAO USAR getAxon(); ANTES DE CHAMAR UM getOutput();

#include <iostream> 
#include <vector>
#include <list>
#include <cstdlib>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#define MIN_AXON -1
#define MAX_AXON 1
//#define ESCOPO_DECIMAL_AXON 100

#define N_INPUTS 2
#define N_NEURONS 4
#define N_OUTPUTS 2

/*
	PARA O USO DA CLASSE:
	1. 	Crie um vetor de doubles com seus inputs, o tamanho do vetor pode ser qualquer um, 
		desde que voce altere o valor da constante N_INPUTS para ficar igual a qtd de inputs
		
	2.	Cria um double que sera seu bias dos neuronios e outro para o bias dos outputs
	
	3.	Altere o numero de NEURONS e OUTPUTS a vontade, pelas constantes no comeco da classe de respectivo nome

	4.1 Instancie a classe e mande os valores dos inputs e do bias no construtor

	4.2 ATENCAO: Ao instanciar a classe, ela automaticamente randomiza os axons. Se quiser randomizar 
		os axons novamente, use a funcao populateAxons()
	
	5. Use os gets e sets a vontade, cheque cada um para ver o que eles retornam ou o que eles recebem

	6. Use a funcao feedForward() para calcular os neuronios e outputs
	
	OBS. Comente os printfs dos metodos se nao quiser que o passo-a-passo seja printado na tela
*/

class RedeNeural {

    private:
    	typedef struct 
		{
			double axonsIn[N_INPUTS][N_NEURONS]; // [x][y] -> [x] é para o input, signifca qual input veio, [y] é para neuronio, signifca para qual neuronio vai
			double axonsOut[N_NEURONS][N_OUTPUTS]; // [x][y] -> [x] é para o neuronio, signifca qual neuronio veio, [y] é para output, signifca para qual output vai
		} structAxons;
		
    	double input[N_INPUTS], output[N_OUTPUTS]; // input e output com seu devido tamanho
        double neuron[N_NEURONS]; // Neuronios para a camada escondida. Nessa classe, ha somente 1 cada escondida, voce pode talvez precisar de 2
		structAxons axons; // Axons para conectar inputs -> neurons -> outputs
        double biasNeuron, biasOutput; // Biases para os neuronios e os outputs, cada um independente se quiser

    public:
    	// CONSTRUCTOR
        RedeNeural(double _input[], double _biasNeuron, double _biasOutput) 
		{
			for(int i = 0; i < N_INPUTS; i++)
			{
				input[i] = _input[i];
			}
			biasNeuron = _biasNeuron;
			biasOutput = _biasOutput;
			populateAxons(); // Isso talvez seja removido depois, ja que popular os axons o usuario q faz uma vez so, e nao a cada construcao
		}
		
		// GETTERS
		double* getInput()
		{
		    return input;
		}
		double* getOutput()
		{
			return output;
		}
		structAxons getAxons()
		{
		    return axons;
		}
		double* getNeuron()
		{
			return neuron;
		}
		double getBiasNeuron()
		{
			return biasNeuron;
		}
		double getBiasOutput()
		{
			return biasOutput;
		}
		
		// SETTERS
		void setInput(double _input[])
		{
		    for(int i = 0; i < N_INPUTS; i++)
			{
				input[i] = _input[i];
			}
		}
		void setOutput(double _output[])
		{
			for(int i = 0; i < N_OUTPUTS; i++)
			{
				output[i] = _output[i];
			}
		}
		void setAxonsIn(double _axonsIn[][N_NEURONS])
		{
			for(int i = 0; i < N_INPUTS; i++)
			{
				for(int j = 0; j < N_NEURONS; j++)
				{
					axons.axonsIn[i][j] = _axonsIn[i][j];
				}
			}
		}
		void setAxonsOut(double _axonsOut[][N_OUTPUTS])
		{
			for(int i = 0; i < N_NEURONS; i++)
			{
				for(int j = 0; j < N_OUTPUTS; j++)
				{
					axons.axonsOut[i][j] = _axonsOut[i][j];
				}
			}
		}
		void setNeuron(double _neuron[])
		{
			for(int i = 0; i < N_NEURONS; i++)
			{
				neuron[i] = _neuron[i];
			}
		}
		void setBiasNeuron(double _biasNeuron)
		{
			biasNeuron = _biasNeuron;
		}
		void setBiasOutput(double _biasOutput)
		{
			biasOutput = _biasOutput;
		}
		
		// METODOS
		void manipulateAxons(double _axonsIn[][N_NEURONS], double _axonsOut[][N_OUTPUTS]) // Forneca os arrays de axons In e Out que quiser que a NN use
		{
			// Funcao inutil, so usa dois sets. Era pra testes mesmo
			setAxonsIn(_axonsIn);
			setAxonsOut(_axonsOut);
		}
		
		void populateAxons()
		{
			srand( (unsigned)time(NULL) );
			
			for(int i = 0; i < N_INPUTS; i++)
			{
				for(int j = 0; j < N_NEURONS; j++)
				{
					// Randomizamos nossos Axons e dividimos eles para termos um axon decimal, que eh limitado pelos MIN_AXON e MAX_AXON
					axons.axonsIn[i][j] = ( ((double) rand() / (double) RAND_MAX) * (MAX_AXON - MIN_AXON) ) + MIN_AXON ;
					
					// E limitamos as casas decimais. Se quiser 3 casas decimais, use 1.000 no ESCOPO_DECIMAL_AXON, e assim vai
					//axons.axonsIn[i][j] = round( axons.axonsIn[i][j] * ESCOPO_DECIMAL_AXON) / ESCOPO_DECIMAL_AXON;
				}
			}
			
			for(int i = 0; i < N_NEURONS; i++)
			{
				for(int j = 0; j < N_OUTPUTS; j++)
				{
					// Randomizamos nossos Axons e dividimos eles para termos um axon decimal, que eh limitado pelos MIN_AXON e MAX_AXON
					axons.axonsOut[i][j] = ( ((double) rand() / (double) RAND_MAX) * (MAX_AXON - MIN_AXON) ) + MIN_AXON ;
					
					// E limitamos as casas decimais. Se quiser 3 casas decimais, use 1.000 no ESCOPO_DECIMAL_AXON, e assim vai
					//axons.axonsOut[i][j] = round( axons.axonsOut[i][j] * ESCOPO_DECIMAL_AXON) / ESCOPO_DECIMAL_AXON;
				}
			}
		}
		
		double sigmoid(double x) // Funcao sigmoid foi usada para o caminho do feedforward, conforme visto no video
		{
			return 1 / (1 + exp(-x));
		}
		
		double dSigmoid(double x)
		{
			return x * (1 - x);
		}
		
		void activatingFunction(double source[], int size) // Funcao de ativacao para ativar qualquer vetor de double que receber, usando sigmoid
		{
			printf("\n");
			for(int i = 0; i < size; i++)
			{
				printf("SIGMOID: Source[%d] era %f... ", i, source[i]);
				source[i] = sigmoid(source[i]);
				printf("depois da sigmoid ficou %f\n\n", source[i]);
			}
		}
		
		void feedForward() // O processo de feedForward, populando os neuronios e os outputs com os calculos vistos
		{
			// Calculo do valor dos neuronios conforme visto aos 11:05 de https://www.youtube.com/watch?v=d8U7ygZ48Sc
			printf("\n\n\tFF DE NEURONIOS\n");
			for(int i = 0; i < N_NEURONS; i++) 
			{
				for(int j = 0; j < N_INPUTS; j++)
				{
					printf("\nNEURON[%d]: Adicionando [ input[%d] * axons.axonsIn[%d][%d] >> %f  * %f ] = %f, totalizando... ", i, j, j, i, input[j], axons.axonsIn[j][i], input[j]*axons.axonsIn[j][i]);
					neuron[i] += input[j] * axons.axonsIn[j][i];
					printf("%f\n", neuron[i]);
				}
				neuron[i] += biasNeuron;
				printf("\nCom bias final de %f, totalizando %f (neuron[%d])\n\n", biasNeuron, neuron[i], i);
			}
			// Para os neuronios na situacao com 2 inputs e 2 neurons, 4 axonsIn, temos que...
			// neuron[0] = input[0] * axons.axonsIn[0][0] + input[1] * axons.axonsIn[1][0]
			// neuron[1] = input[0] * axons.axonsIn[0][1] + input[1] * axons.axonsIn[1][1]
			
			activatingFunction(neuron, N_NEURONS);
			
			// Calculo do valor dos neuronios conforme visto aos 13:58 de https://www.youtube.com/watch?v=d8U7ygZ48Sc
			printf("\n\n\tFF DE OUTPUTS\n");
			for(int i = 0; i < N_OUTPUTS; i++) // A cada neuronio, faca...
			{
				for(int j = 0; j < N_NEURONS; j++) // A cada output, faca
				{
					printf("\nOUTPUT[%d]: Adicionando [ neuron[%d] * axons.axonsOut[%d][%d] >> %f  * %f ] = %f, totalizando... ", i, j, j, i, neuron[j], axons.axonsOut[j][i], neuron[j]*axons.axonsOut[j][i]);
					output[i] += neuron[j] * axons.axonsOut[j][i];
					printf("%f\n", output[i]);
				}
				output[i] += biasOutput;
				printf("\nCom bias final de %f, totalizando %f (output[%d])\n\n", biasOutput, output[i], i);
			}
			// Para os outputs na situacao com 2 neurons e 2 outputs, 4 axonsOut, temos que...
			// output[0] = neuron[0] * axons.axonsOut[0][0] + neuron[1] * axons.axonsOut[1][0]
			// output[1] = neuron[0] * axons.axonsOut[0][1] + neuron[1] * axons.axonsOut[1][1]
			
			activatingFunction(output, N_OUTPUTS);
		}
		
		void printExample() // Exemplo de caso de uso bobinho
		{
			double _inputs[] = {1, 2};
			double _biasNeuron = 0;
			double _biasOutput = 0;
			RedeNeural n(_inputs, _biasNeuron, _biasOutput); 
			n.feedForward();
			
			printf("\n\n\tCASO DE TESTE INPUT [1,2] BIAS TODOS 0\n\n");
			for(int i = 0; i < N_INPUTS; i++) 
				printf("Input[%d]: %f\n", i, n.getInput()[i]);
			printf("----\n");
			
			for(int i = 0; i < N_INPUTS; i++) 
				for(int j = 0; j < N_NEURONS; j++)
					printf("AxonIn[%d][%d]: %f\n", i, j, n.getAxons().axonsIn[i][j]);
			printf("----\n");
			
			for(int i = 0; i < N_NEURONS; i++) 
				printf("Neuron[%d]: %f\n", i, n.getNeuron()[i]);
			printf("----\n");
			
			printf("Bias Neuronio (adicionado no neuronio antes da sigmoid): %f\n", n.getBiasNeuron());
			printf("----\n");
			
			for(int i = 0; i < N_NEURONS; i++) 
				for(int j = 0; j < N_OUTPUTS; j++)
					printf("AxonOut[%d][%d]: %f\n", i, j, n.getAxons().axonsOut[i][j]);
			printf("----\n");
			
			for(int i = 0; i < N_OUTPUTS; i++) 
				printf("Output[%d]: %f\n", i, n.getOutput()[i]);
			printf("----\n");
			
			printf("Bias Output (adicionado no output antes da sigmoid): %f\n", n.getBiasOutput());
			printf("----\n");
		}
}; 

// Um exemplo de main que o dev faria
int main() 
{   
	double _inputs[] = {6,7};
	double _biasNeuron = 0;
	double _biasOutput = 0;
	RedeNeural n(_inputs, _biasNeuron, _biasOutput);
	n.feedForward();
	
	printf("\n\n\tRESUMINDO\n\n");
	for(int i = 0; i < N_INPUTS; i++) 
		printf("Input[%d]: %f\n", i, n.getInput()[i]);
	printf("----\n");
	
	for(int i = 0; i < N_INPUTS; i++) 
		for(int j = 0; j < N_NEURONS; j++)
			printf("AxonIn[%d][%d]: %f\n", i, j, n.getAxons().axonsIn[i][j]);
	printf("----\n");
	
	for(int i = 0; i < N_NEURONS; i++) 
		printf("Neuron[%d]: %f\n", i, n.getNeuron()[i]);
	printf("----\n");
	
	printf("Bias Neuronio (adicionado no neuronio antes da sigmoid): %f\n", n.getBiasNeuron());
	printf("----\n");
	
	for(int i = 0; i < N_NEURONS; i++) 
		for(int j = 0; j < N_OUTPUTS; j++)
			printf("AxonOut[%d][%d]: %f\n", i, j, n.getAxons().axonsOut[i][j]);
	printf("----\n");
	
	for(int i = 0; i < N_OUTPUTS; i++) 
		printf("Output[%d]: %f\n", i, n.getOutput()[i]);
	printf("----\n");
	
	printf("Bias Output (adicionado no output antes da sigmoid): %f\n", n.getBiasOutput());
	printf("----\n");
	 
	return 0; 
}
