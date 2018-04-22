/*
 * Copyright (C) 2017 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     rekols <rekols@foxmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "popupcontent.h"
#include <QVBoxLayout>
#include <QLabel>

PopupContent::PopupContent(QWidget *parent)
    : DAbstractDialog(parent)
{
    DBlurEffectWidget *bgWidget = new DBlurEffectWidget(this);
    bgWidget->setBlendMode(DBlurEffectWidget::BehindWindowBlend);
    bgWidget->setMaskColor(DBlurEffectWidget::LightColor);

    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel("deepin translation");
    layout->addWidget(label);

    setFixedSize(600, 200);
    bgWidget->resize(size());

    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_DeleteOnClose, true);
    setAttribute(Qt::WA_AlwaysStackOnTop);
}

PopupContent::~PopupContent()
{
}
