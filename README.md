# Sistema de Monitoreo y Prevención de Incidentes Mineros

**Proyecto – BIC01: Introducción a la Computación (C++)**

## 🥚 Descripción del Proyecto

Este proyecto implementa un **sistema de simulación en C++** que registra, monitorea y analiza incidentes y accidentes laborales dentro de una operación minera.
El sistema genera eventos aleatorios, evalúa umbrales de riesgo, calcula indicadores de seguridad y muestra un reporte final consolidado.

## 🤢 Objetivo General

Simular el proceso real de control de Seguridad y Salud Ocupacional (SSO), usando programación estructurada en C++:

* Variables
* Condicionales
* Bucles
* Arreglos
* Contadores y acumuladores
* Funciones (aunque el profe se retracto)

## 🗣️ Contexto

La empresa minera ficticia **AndeSur S.A.C.**, ubicada en Arequipa, maneja reportes diarios de incidentes.
El programa ayuda a identificar eventos críticos y calcular indicadores de seguridad como TF, TS e II.

## 🥵 Catálogo de Eventos

El sistema utiliza arreglos paralelos:

| Código | Tipo de Evento          |
| ------ | ----------------------- |
| E001   | Incidente sin lesión    |
| E002   | Accidente leve          |
| E003   | Accidente incapacitante |
| E004   | Accidente fatal         |
| E005   | Casi accidente          |

## 😒 Funcionalidades Principales

### 1) **Simulación de Registros**

* Genera entre **80 y 100** eventos aleatorios.
* Cada evento tiene:

  * Código del catálogo
  * Área aleatoria (Mina Subterránea, Planta, Mantenimiento, Logística, Geología)

### 2) **Alertas**

* Si un tipo de evento llega a **10 o más casos**, se activa una **alerta**.

### 3) **Cálculo de Indicadores**

El usuario ingresa el número total de trabajadores y el sistema calcula:

* **Horas-Hombre al año**
* **Tasa de Frecuencia (TF)**
* **Tasa de Severidad (TS)**
* **Índice de Incidentabilidad (II)**
  Todos con **2 decimales**.

### 4) **Reporte Final**

Incluye:

* Conteos por tipo de evento
* Alertas activas
* Indicadores TF, TS, II
* Recomendación automática:

  * TF > 10 o TS > 20 → *Reforzar capacitaciones*
  * Caso contrario → *Mantener controles actuales*

## 👨🏿‍🦽‍➡️ Tecnologías y Restricciones

* Lenguaje: **C++ en modo consola**
* **No se permite:** `vector`, `struct`, archivos, ni librerías externas.
* Se debe usar:

  * `for`, `while`, `if/else`
  * Arreglos unidimensionales
  * Funciones (ya ño)
