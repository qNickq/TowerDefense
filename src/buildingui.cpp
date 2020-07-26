#include "buildingui.h"

BuildingUI::BuildingUI(QWidget *parent) : QWidget(parent)
{
    v_box.setAlignment(Qt::AlignTop);

    QLabel * name = new QLabel("<b>Towers:<b>");
    UiObject * obj = new UiObject();
    QLabel * cost = new QLabel(QString("Cost: %1").arg(obj->getCost()));
    QLabel * radius = new QLabel("Radius: 200");
    QLabel * power = new QLabel( QString("Power: 30"));

    list.push_back(name);
    list.push_back(obj);
    list.push_back(cost);
    list.push_back(radius);
    list.push_back(power);

    connect(obj, SIGNAL(create()), this, SLOT(sendBuild()));

    for(auto wgt : list)
    {
        v_box.addWidget(wgt);
    }
    this->setContentsMargins(1,1,1,1);
    this->setLayout(&v_box);
}

void BuildingUI::sendBuild()
{
    emit build();
}

void BuildingUI::setPossible(int money)
{
    for(auto i : list)
    {
        if (UiObject * obj = dynamic_cast<UiObject*>(i))
        {
            if(money < obj->getCost())
            {
                i->setEnabled(false);
            }
            else
            {
                i->setEnabled(true);
            }
        }
    }
}


