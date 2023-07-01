#!/bin/bash

cppath=$(dirname ${0})

ABC_PATH=$cppath/../AtCoder/ABC
ARC_PATH=$cppath/../AtCoder/ARC
AGC_PATH=$cppath/../AtCoder/AGC
ABCex_PATH=$cppath/../AtCoder/ABCex
ARCex_PATH=$cppath/../AtCoder/ARCex
AGCex_PATH=$cppath/../AtCoder/AGCex
DIV1_PATH=$cppath/../CodeForces/div1
DIV2_PATH=$cppath/../CodeForces/div2
DIV3_PATH=$cppath/../CodeForces/div3
ECR_PATH=$cppath/../CodeForces/ECR

items=(
    $ABC_PATH
    $ARC_PATH
    $AGC_PATH
    $ABCex_PATH
    $ARCex_PATH
    $AGCex_PATH
    $DIV1_PATH
    $DIV2_PATH
    $DIV3_PATH
    $ECR_PATH
)

for item in "${items[@]}";
do
    rm -rf $item/template
    mkdir $item/template
    cp $cppath/template.cpp $item/template
done

ABCDEFGitems=(
    $ABC_PATH
    $ARC_PATH
    $AGC_PATH
)

for item in "${ABCDEFGitems[@]}";
do
    cp $item/template/template.cpp $item/template/a.cpp
    cp $item/template/template.cpp $item/template/b.cpp
    cp $item/template/template.cpp $item/template/c.cpp
    cp $item/template/template.cpp $item/template/d.cpp
    cp $item/template/template.cpp $item/template/e.cpp
    cp $item/template/template.cpp $item/template/f.cpp
    cp $item/template/template.cpp $item/template/g.cpp
done