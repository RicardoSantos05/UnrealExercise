#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MyDoorInterface.generated.h"

// Forward declaration para evitar dependência circular
class AActor;

// Blueprintable permite usar esta interface nos Blueprints
UINTERFACE(Blueprintable)
class MYUNREALEXERCISE_API UMyDoorInterface : public UInterface
{
	GENERATED_BODY()
};

// Implementação C++ da interface
class MYUNREALEXERCISE_API IMyDoorInterface
{
	GENERATED_BODY()

public:
	// Função que pode ser implementada em C++ ou Blueprint
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void Interact(AActor* Interactor);
};