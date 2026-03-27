agenda = []

def adicionar_compromisso():
    data = input("Digite a data (dd/mm/aaaa): ")
    hora = input("Digite a hora (hh:mm): ")
    descricao = input("Descrição do compromisso: ")
    
    compromisso = {
        "data": data,
        "hora": hora,
        "descricao": descricao
    }
    
    agenda.append(compromisso)
    print(" Compromisso adicionado com sucesso!\n")


def listar_compromissos():
    if not agenda:
        print(" Nenhum compromisso na agenda.\n")
        return
    
    print("\n Seus compromissos:")
    for i, comp in enumerate(agenda):
        print(f"{i+1}. {comp['data']} às {comp['hora']} - {comp['descricao']}")
    print()


def remover_compromisso():
    listar_compromissos()
    
    if agenda:
        try:
            indice = int(input("Digite o número do compromisso para remover: ")) - 1
            if 0 <= indice < len(agenda):
                agenda.pop(indice)
                print(" Compromisso removido!\n")
            else:
                print(" Número inválido.\n")
        except ValueError:
            print(" Entrada inválida.\n")


def menu():
    while True:
        print("=== AGENDA ===")
        print("1. Adicionar compromisso")
        print("2. Listar compromissos")
        print("3. Remover compromisso")
        print("4. Sair")
        
        opcao = input("Escolha uma opção: ")
        
        if opcao == "1":
            adicionar_compromisso()
        elif opcao == "2":
            listar_compromissos()
        elif opcao == "3":
            remover_compromisso()
        elif opcao == "4":
            print(" Saindo da agenda...")
            break
        else:
            print(" Opção inválida.\n")



menu()