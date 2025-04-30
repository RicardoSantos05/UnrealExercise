#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoorInteractable.generated.h"

UCLASS()
class MYUNREALEXERCISE_API ADoorInteractable : public AActor
{
	GENERATED_BODY()

public:
	ADoorInteractable();

	// Função que será chamada pelo personagem ao interagir
	UFUNCTION(BlueprintImplementableEvent, Category = "Interaction")
	void Interact(AActor* Interactor);
};