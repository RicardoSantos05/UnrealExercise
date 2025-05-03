#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyDoorInterface.h"
#include "DoorInteractable.generated.h"

// Classe de porta que implementa a interface de interação
UCLASS()
class MYUNREALEXERCISE_API ADoorInteractable : public AActor, public IMyDoorInterface
{
	GENERATED_BODY()

public:
	// Construtor padrão
	ADoorInteractable();

	// Sobrescrita da função Interact da interface
	virtual void Interact_Implementation(AActor* Interactor) override;
};