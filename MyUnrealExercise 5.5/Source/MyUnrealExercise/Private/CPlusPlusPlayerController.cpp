#include "CPlusPlusPlayerController.h"
#include "AlternativeCPlusPlus.h"
#include "GameFramework/Actor.h"

void ACPlusPlusPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ControlledCharacter = Cast<AAlternativeCPlusPlus>(GetPawn());
}

void ACPlusPlusPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACPlusPlusPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &ACPlusPlusPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ACPlusPlusPlayerController::MoveRight);
	InputComponent->BindAction("Interact", IE_Pressed, this, &ACPlusPlusPlayerController::Interact);
}

void ACPlusPlusPlayerController::MoveForward(float Value)
{
	if (ControlledCharacter && Value != 0.f)
	{
		FRotator YawRotation(0, GetControlRotation().Yaw, 0);
		FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		ControlledCharacter->AddMovementInput(Direction, Value);
	}
}

void ACPlusPlusPlayerController::MoveRight(float Value)
{
	if (ControlledCharacter && Value != 0.f)
	{
		FRotator YawRotation(0, GetControlRotation().Yaw, 0);
		FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		ControlledCharacter->AddMovementInput(Direction, Value);
	}
}

void ACPlusPlusPlayerController::Interact()
{
	if (ControlledCharacter)
	{
		ControlledCharacter->Interact();
	}
}