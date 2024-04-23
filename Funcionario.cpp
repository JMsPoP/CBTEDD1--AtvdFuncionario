#include <iostream>
#include <string>
using namespace std;

// classe funcionario
class Funcionario {
private:
    int prontuario;
    string nome;
    double salario;

public:
    // construtor
    Funcionario(int p = 0, const string& n = "", double s = 0.0) : prontuario(p), nome(n), salario(s) {}

    int getProntuario() const { return prontuario; }
    void setProntuario(int p) { prontuario = p; }

    string getNome() const { return nome; }
    void setNome(const string& n) { nome = n; }

    double getSalario() const { return salario; }
    void setSalario(double s) { salario = s; }

    // exibir os dados do funcionario
    void exibirFuncionario() const {
        cout << "---------------------" << endl;
        cout << "| Prontuario: " << prontuario << endl;
        cout << "| Nome: " << nome << endl;
        cout << "| Salario: " << salario << endl;
        cout << "---------------------" << endl;
    }

    // método para inserir os dados do funcionario
    void inserirFuncionario(Funcionario funcionarios[], int tamanho) {
        int novoProntuario;
        bool prontuarioExistente;

        do {
            prontuarioExistente = false;

            cout << "Digite o prontuario: ";
            cin >> novoProntuario;

            // Verifica se o prontuário já existe
            for (int i = 0; i < tamanho; i++) {
                if (funcionarios[i].getProntuario() == novoProntuario) {
                    prontuarioExistente = true;
                    cout << "Prontuario ja existe. Digite outro prontuario." << endl;
                    break;
                }
            }
        } while (prontuarioExistente);

        prontuario = novoProntuario;

        cout << "Digite o nome: ";
        cin.ignore();
        getline(cin, nome);

        cout << "Digite o salario: ";
        cin >> salario;
    }
};

int main() {
    Funcionario funcionarios[99];
    int opcao, prontuarioBusca;

    do {
        cout << "Selecione uma opcao:" << endl;
        cout << "0 - Sair" << endl;
        cout << "1 - Inserir funcionario" << endl;
        cout << "2 - Excluir" << endl;
        cout << "3 - Procurar funcionario" << endl;
        cout << "4 - Listar" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "Saindo do programa..." << endl;
                break;
            case 1:
                for (int i = 0; i < 99; i++) {
                    if (funcionarios[i].getProntuario() == 0) {
                        funcionarios[i].inserirFuncionario(funcionarios, 2);
                        break;
                    }
                }
                break;
            case 2:
                cout << "Digite o prontuario a ser excluido: ";
                cin >> prontuarioBusca;
                for (int i = 0; i < 99; i++) {
                    if (funcionarios[i].getProntuario() == prontuarioBusca) {
                        funcionarios[i] = Funcionario();
                        cout << "Funcionario excluido" << endl;
                        break;
                    } else {
                        cout << "Prontuario nao encontrado." << endl;
                    }
                }
                break;
            case 3:
                cout << "Digite o prontuario a ser buscado: ";
                cin >> prontuarioBusca;
                for (int i = 0; i < 99; i++) {
                    if (funcionarios[i].getProntuario() == prontuarioBusca) {
                        funcionarios[i].exibirFuncionario();
                        break;
                    } else {
                        cout << "Prontuario nao encontrado." << endl;
                    }
                }
                break;
            case 4: {
                double totalSalarios = 0.0;
                cout << "Listagem de funcionarios:" << endl;
                for (int i = 0; i < 99; i++) {
                    if (funcionarios[i].getProntuario() != 0) {
                        funcionarios[i].exibirFuncionario();
                        totalSalarios += funcionarios[i].getSalario();
                    }
                }
                cout << "Total de salarios: " << totalSalarios << endl;
                break;
            }
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
                break;
        }
    } while (opcao != 0);

    return 0;
}
