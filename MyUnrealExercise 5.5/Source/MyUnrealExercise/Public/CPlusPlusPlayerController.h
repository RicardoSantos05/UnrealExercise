#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CPlusPlusPlayerController.generated.h"

class AAlternativeCPlusPlus;

UCLASS()
class MYUNREALEXERCISE_API ACPlusPlusPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupInputComponent() override;

private:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Interact();

	AAlternativeCPlusPlus* ControlledCharacter;
};