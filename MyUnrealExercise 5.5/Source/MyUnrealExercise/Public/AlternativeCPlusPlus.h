#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AlternativeCPlusPlus.generated.h"

class ADoorInteractable; // Forward declaration

UCLASS()
class MYUNREALEXERCISE_API AAlternativeCPlusPlus : public ACharacter
{
	GENERATED_BODY()

public:
	AAlternativeCPlusPlus();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void Interact();

private:
	UPROPERTY()
	AActor* CurrentLookTarget;
};