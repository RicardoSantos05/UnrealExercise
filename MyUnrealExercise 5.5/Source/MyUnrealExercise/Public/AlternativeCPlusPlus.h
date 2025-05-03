#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AlternativeCPlusPlus.generated.h"

UCLASS()
class MYUNREALEXERCISE_API AAlternativeCPlusPlus : public ACharacter
{
	GENERATED_BODY()

public:
	AAlternativeCPlusPlus();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	void Interact();

private:
	void TraceForInteractable();
	AActor* CurrentLookTarget = nullptr;
};