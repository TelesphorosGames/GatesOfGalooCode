// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Enemy.h"
#include "Kismet/KismetMathLibrary.h"
#include "Weapon.h"

 void UEnemyAnimInstance::NativeInitializeAnimation()
 {
    if(Pawn == nullptr)
    {
        Pawn = TryGetPawnOwner();
        if(Pawn)
        {
        Enemy= Cast<AEnemy>(Pawn);
        }
    }
 }

void UEnemyAnimInstance::UpdateAnimationProperties()
{
    if(Pawn == nullptr)
    {
        Pawn = TryGetPawnOwner();
        Enemy= Cast<AEnemy>(Pawn);
    }
        if(Pawn && Enemy->Alive())
        {
            FVector Speed = Pawn->GetVelocity();
            FVector LateralSpeed = {Speed.X, Speed.Y, 0};
            SpiderMovementSpeed = LateralSpeed.Size();
        
        }
}