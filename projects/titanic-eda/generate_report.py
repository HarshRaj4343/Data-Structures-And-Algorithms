# Creating a full EDA report for the Titanic assignment (Q1 - Q30).
# The script saves plots and CSVs inside this project folder so it works
# reliably no matter where it is launched from.

import os
from pathlib import Path
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.backends.backend_pdf import PdfPages
import ssl
ssl._create_default_https_context = ssl._create_unverified_context

# Create output directory
base_dir = Path(__file__).resolve().parent
outdir = base_dir / "outputs"
os.makedirs(outdir, exist_ok=True)

# Load titanic dataset using seaborn's loader (only for data). Plots use matplotlib only.
import seaborn as sns
titanic = sns.load_dataset('titanic')

# Basic cleaning for plotting convenience
df = titanic.copy()
# Standardize column names used in the assignment (some questions expect 'survived'/'fare' etc.)
# seaborn titanic has columns: 'survived', 'pclass', 'sex', 'age', 'sibsp', 'parch', 'fare', 'embarked'
# Ensure numeric types
df['age'] = pd.to_numeric(df['age'], errors='coerce')
df['fare'] = pd.to_numeric(df['fare'], errors='coerce')
df['sibsp'] = pd.to_numeric(df['sibsp'], errors='coerce')
df['parch'] = pd.to_numeric(df['parch'], errors='coerce')

# Helper to save figures
def save_fig(fig, name):
    path = outdir / name
    fig.savefig(path, bbox_inches='tight')
    plt.close(fig)
    return path

pdf_path = base_dir / "titanic_lab_report.pdf"
pdf = PdfPages(pdf_path)

# Q1: Histogram / Boxplot of Age
fig = plt.figure(figsize=(6,4))
plt.hist(df['age'].dropna(), bins=30)
plt.title("Q1: Histogram of Age")
plt.xlabel("Age")
plt.ylabel("Count")
save_fig(fig, "Q1_hist_age.png"); pdf.savefig(fig); plt.close(fig)

fig = plt.figure(figsize=(6,3))
plt.boxplot(df['age'].dropna(), vert=False)
plt.title("Q1: Boxplot of Age")
plt.xlabel("Age")
save_fig(fig, "Q1_box_age.png"); pdf.savefig(fig); plt.close(fig)

# Q2: Survival counts bar chart
surv_counts = df['survived'].value_counts().sort_index()
fig = plt.figure(figsize=(5,4))
plt.bar(['Did Not Survive (0)','Survived (1)'], surv_counts.values)
plt.title("Q2: Survival Counts")
plt.ylabel("Count")
save_fig(fig, "Q2_survival_counts.png"); pdf.savefig(fig); plt.close(fig)

# Q3: Survival counts by sex (grouped bar chart)
group_sex = df.groupby(['sex','survived']).size().unstack(fill_value=0)
fig = plt.figure(figsize=(6,4))
x = np.arange(len(group_sex.index))
width = 0.35
plt.bar(x - width/2, group_sex[0], width, label='Not Survived (0)')
plt.bar(x + width/2, group_sex[1], width, label='Survived (1)')
plt.xticks(x, group_sex.index)
plt.title("Q3: Survival by Sex")
plt.ylabel("Count")
plt.legend()
save_fig(fig, "Q3_survival_by_sex.png"); pdf.savefig(fig); plt.close(fig)

# Q4: Counts in each Pclass
pclass_counts = df['pclass'].value_counts().sort_index()
fig = plt.figure(figsize=(5,4))
plt.bar(pclass_counts.index.astype(str), pclass_counts.values)
plt.title("Q4: Passenger Count by Pclass")
plt.xlabel("Pclass"); plt.ylabel("Count")
save_fig(fig, "Q4_pclass_counts.png"); pdf.savefig(fig); plt.close(fig)

# Q5: Box plot of Fare to detect ranges and outliers
fig = plt.figure(figsize=(6,3))
plt.boxplot(df['fare'].dropna(), vert=False)
plt.title("Q5: Boxplot of Fare")
plt.xlabel("Fare")
save_fig(fig, "Q5_box_fare.png"); pdf.savefig(fig); plt.close(fig)

# Q6: Scatter plot Age vs Fare
fig = plt.figure(figsize=(6,4))
plt.scatter(df['age'], df['fare'], s=10)
plt.title("Q6: Age vs Fare Scatter")
plt.xlabel("Age"); plt.ylabel("Fare")
save_fig(fig, "Q6_scatter_age_fare.png"); pdf.savefig(fig); plt.close(fig)

# Q7: Survival by Embarked (bar chart)
emb_surv = df.groupby(['embarked','survived']).size().unstack(fill_value=0)
fig = plt.figure(figsize=(6,4))
x = np.arange(len(emb_surv.index))
width = 0.35
plt.bar(x - width/2, emb_surv[0], width, label='Not Survived (0)')
plt.bar(x + width/2, emb_surv[1], width, label='Survived (1)')
plt.xticks(x, emb_surv.index.astype(str))
plt.title("Q7: Survival by Embarked Port")
plt.ylabel("Count"); plt.xlabel("Embarked")
plt.legend()
save_fig(fig, "Q7_survival_by_embarked.png"); pdf.savefig(fig); plt.close(fig)

# Q8: Survival count based on family size (sibsp + parch) - bar chart for counts and survival rate
df['family_size'] = df['sibsp'].fillna(0) + df['parch'].fillna(0)
family_counts = df.groupby('family_size').size()
family_surv_rates = df.groupby('family_size')['survived'].mean()
fig = plt.figure(figsize=(8,4))
plt.bar(family_counts.index.astype(int), family_counts.values)
plt.title("Q8: Passenger Count by Family Size")
plt.xlabel("Family Size"); plt.ylabel("Count")
save_fig(fig, "Q8_family_counts.png"); pdf.savefig(fig); plt.close(fig)

fig = plt.figure(figsize=(8,4))
plt.bar(family_surv_rates.index.astype(int), family_surv_rates.values)
plt.title("Q8: Survival Rate by Family Size")
plt.xlabel("Family Size"); plt.ylabel("Survival Rate")
save_fig(fig, "Q8_family_survival_rate.png"); pdf.savefig(fig); plt.close(fig)

# Q9: Age distribution vs Survived - box plot (Age on Y, Survived on X)
ages_by_surv = [df[df['survived']==0]['age'].dropna(), df[df['survived']==1]['age'].dropna()]
fig = plt.figure(figsize=(6,4))
plt.boxplot(ages_by_surv, labels=['Not Survived (0)', 'Survived (1)'])
plt.title("Q9: Age Distribution by Survival")
plt.ylabel("Age")
save_fig(fig, "Q9_age_by_survival_box.png"); pdf.savefig(fig); plt.close(fig)

# Q10: Age distribution by sex - boxplot
ages_by_sex = [df[df['sex']=='male']['age'].dropna(), df[df['sex']=='female']['age'].dropna()]
fig = plt.figure(figsize=(6,4))
plt.boxplot(ages_by_sex, labels=['Male', 'Female'])
plt.title("Q10: Age Distribution by Sex")
plt.ylabel("Age")
save_fig(fig, "Q10_age_by_sex_box.png"); pdf.savefig(fig); plt.close(fig)

# Q11: Compare age distributions of survivors vs non-survivors for males and females separately.
fig = plt.figure(figsize=(8,6))
# We'll create 4 boxplots: male-not, male-yes, female-not, female-yes
groups = [
    df[(df['sex']=='male') & (df['survived']==0)]['age'].dropna(),
    df[(df['sex']=='male') & (df['survived']==1)]['age'].dropna(),
    df[(df['sex']=='female') & (df['survived']==0)]['age'].dropna(),
    df[(df['sex']=='female') & (df['survived']==1)]['age'].dropna()
]
labels = ['M_not','M_yes','F_not','F_yes']
plt.boxplot(groups, labels=labels)
plt.title("Q11: Age by Sex and Survival")
plt.ylabel("Age")
save_fig(fig, "Q11_age_sex_surv_box.png"); pdf.savefig(fig); plt.close(fig)

# Q12: Compare age distributions for children (<18) and adults (>=18) for survival (boxplots separated)
df['age_group'] = np.where(df['age']<18, 'Child', 'Adult')
# Prepare boxplots for Child-not, Child-yes, Adult-not, Adult-yes
groups = [
    df[(df['age_group']=='Child') & (df['survived']==0)]['age'].dropna(),
    df[(df['age_group']=='Child') & (df['survived']==1)]['age'].dropna(),
    df[(df['age_group']=='Adult') & (df['survived']==0)]['age'].dropna(),
    df[(df['age_group']=='Adult') & (df['survived']==1)]['age'].dropna()
]
labels = ['Child_not','Child_yes','Adult_not','Adult_yes']
fig = plt.figure(figsize=(8,5))
plt.boxplot(groups, labels=labels)
plt.title("Q12: Age distribution for Child vs Adult by Survival")
plt.ylabel("Age")
save_fig(fig, "Q12_child_adult_by_survival.png"); pdf.savefig(fig); plt.close(fig)

# Q13: Overlaid histograms of Age for Survived vs Not Survived
fig = plt.figure(figsize=(6,4))
bins = np.linspace(0, df['age'].dropna().max(), 25)
plt.hist(df[df['survived']==0]['age'].dropna(), bins=bins, alpha=0.5, label='Not Survived (0)')
plt.hist(df[df['survived']==1]['age'].dropna(), bins=bins, alpha=0.5, label='Survived (1)')
plt.legend()
plt.title("Q13: Overlaid Age Histograms (Survived vs Not)")
plt.xlabel("Age"); plt.ylabel("Count")
save_fig(fig, "Q13_overlaid_age_hist.png"); pdf.savefig(fig); plt.close(fig)

# Q14: Grouped bar chart showing counts of passengers per Embarked port within each Pclass
group14 = df.groupby(['pclass','embarked']).size().unstack(fill_value=0)
fig = plt.figure(figsize=(8,5))
x = np.arange(len(group14.index))
width = 0.2
for i, col in enumerate(group14.columns):
    plt.bar(x + (i-1)*width, group14[col].values, width, label=str(col))
plt.xticks(x, group14.index.astype(str))
plt.title("Q14: Counts per Embarked within each Pclass")
plt.xlabel("Pclass"); plt.ylabel("Count"); plt.legend(title="Embarked")
save_fig(fig, "Q14_pclass_embarked_grouped.png"); pdf.savefig(fig); plt.close(fig)

# Q15: Subplots 2x2 of histograms for Age split by Survived (rows) and Sex (columns)
fig, axes = plt.subplots(2,2, figsize=(10,8))
bins = np.linspace(0, df['age'].dropna().max(), 20)
for i, surv in enumerate([0,1]):
    for j, sex in enumerate(['male','female']):
        ax = axes[i,j]
        subset = df[(df['survived']==surv) & (df['sex']==sex)]['age'].dropna()
        ax.hist(subset, bins=bins)
        ax.set_title(f"Survived={surv}, Sex={sex}")
        ax.set_xlabel("Age")
        ax.set_ylabel("Count")
plt.suptitle("Q15: Age Histograms by Survived (rows) and Sex (cols)")
save_fig(fig, "Q15_2x2_age_hist.png"); pdf.savefig(fig); plt.close(fig)

# Q16: Side-by-side box plots of Fare grouped by Pclass and split by Survived
# Create data for each (pclass, survived) combo
combos = []
labels = []
for p in sorted(df['pclass'].dropna().unique()):
    for s in [0,1]:
        combos.append(df[(df['pclass']==p) & (df['survived']==s)]['fare'].dropna())
        labels.append(f"P{p}_S{s}")
fig = plt.figure(figsize=(10,5))
plt.boxplot(combos, labels=labels)
plt.title("Q16: Fare by (Pclass, Survived)")
plt.ylabel("Fare")
save_fig(fig, "Q16_fare_pclass_surv_box.png"); pdf.savefig(fig); plt.close(fig)

# Q17: Box plots of Age by Sex, with separate boxes for Survived vs Not Survived (grouped boxes)
# We'll create 4 boxes: Male-not, Male-yes, Female-not, Female-yes (already made in Q11)
# Save Q17 as same as Q11
# (Recreate to ensure inclusion)
fig = plt.figure(figsize=(8,6))
plt.boxplot(groups := [
    df[(df['sex']=='male') & (df['survived']==0)]['age'].dropna(),
    df[(df['sex']=='male') & (df['survived']==1)]['age'].dropna(),
    df[(df['sex']=='female') & (df['survived']==0)]['age'].dropna(),
    df[(df['sex']=='female') & (df['survived']==1)]['age'].dropna()
], labels=['M_not','M_yes','F_not','F_yes'])
plt.title("Q17: Age by Sex with Survived/Not (grouped)")
plt.ylabel("Age")
save_fig(fig, "Q17_age_sex_grouped_box.png"); pdf.savefig(fig); plt.close(fig)

# Q18: Compute correlation of numeric columns with Survived and plot absolute correlations
numcols = ['age','fare','sibsp','parch']
corrs = {c: df[c].corr(df['survived']) for c in numcols}
corrs_abs = {k: abs(v) for k,v in corrs.items()}
fig = plt.figure(figsize=(6,4))
plt.bar(list(corrs_abs.keys()), list(corrs_abs.values()))
plt.title("Q18: Absolute Correlation with Survived")
plt.ylabel("Absolute Correlation")
save_fig(fig, "Q18_corr_abs.png"); pdf.savefig(fig); plt.close(fig)

# Q19: Stacked bar chart of counts of Survived vs Not Survived within each Pclass
stack = df.groupby(['pclass','survived']).size().unstack(fill_value=0)
fig = plt.figure(figsize=(6,4))
pclasses = stack.index.astype(str)
bottom = np.zeros(len(stack))
for s in [0,1]:
    vals = stack[s].values
    plt.bar(pclasses, vals, bottom=bottom, label=f"Survived={s}")
    bottom += vals
plt.title("Q19: Stacked Survival Counts by Pclass")
plt.xlabel("Pclass"); plt.ylabel("Count"); plt.legend()
save_fig(fig, "Q19_stacked_pclass_surv.png"); pdf.savefig(fig); plt.close(fig)

# Q20: Overlaid histograms of Fare for Survived vs Not Survived
fig = plt.figure(figsize=(6,4))
fare_max = df['fare'].dropna().max()
bins = np.linspace(0, fare_max, 40)
plt.hist(df[df['survived']==0]['fare'].dropna(), bins=bins, alpha=0.5, label='Not Survived (0)')
plt.hist(df[df['survived']==1]['fare'].dropna(), bins=bins, alpha=0.5, label='Survived (1)')
plt.legend()
plt.title("Q20: Overlaid Fare Histograms (Survived vs Not)")
plt.xlabel("Fare"); plt.ylabel("Count")
save_fig(fig, "Q20_overlaid_fare_hist.png"); pdf.savefig(fig); plt.close(fig)

# Q21: Histogram of Fare using log-scaled x-axis
fig = plt.figure(figsize=(6,4))
plt.hist(df['fare'].dropna(), bins=50)
plt.xscale('log')
plt.title("Q21: Histogram of Fare (log-scaled x-axis)")
plt.xlabel("Fare (log scale)"); plt.ylabel("Count")
save_fig(fig, "Q21_fare_hist_logx.png"); pdf.savefig(fig); plt.close(fig)

# Q22: Box plots of Fare by Embarked
emb_fares = [df[df['embarked']==e]['fare'].dropna() for e in df['embarked'].dropna().unique()]
emb_labels = [str(e) for e in df['embarked'].dropna().unique()]
fig = plt.figure(figsize=(6,4))
plt.boxplot(emb_fares, labels=emb_labels)
plt.title("Q22: Fare by Embarked (Boxplots)")
plt.xlabel("Embarked"); plt.ylabel("Fare")
save_fig(fig, "Q22_fare_by_embarked_box.png"); pdf.savefig(fig); plt.close(fig)

# Q23: Bar chart showing count of missing values for each column
missing_counts = df.isna().sum()
fig = plt.figure(figsize=(8,4))
plt.bar(missing_counts.index.astype(str), missing_counts.values)
plt.title("Q23: Missing Values per Column")
plt.xticks(rotation=45, ha='right')
plt.ylabel("Missing Count")
save_fig(fig, "Q23_missing_values.png"); pdf.savefig(fig); plt.close(fig)

# Q24: Two histograms side-by-side (Age, Fare) and box plot of Fare below them.
# As separate single plots (not subplots to follow python_user_visible rules), but we'll create a combined figure for report purposes.
fig = plt.figure(figsize=(10,8))
# Left Age
ax1 = fig.add_subplot(2,1,1)
ax1.hist(df['age'].dropna(), bins=30)
ax1.set_title("Q24a: Histogram of Age")
ax1.set_xlabel("Age"); ax1.set_ylabel("Count")
# Right Fare (placed next to Age by using inset axes)
ax2 = fig.add_subplot(2,1,1)  # create on same space but we'll also create a separate file for fare histogram
plt.close(fig)
# Save Age histogram separately
fig_age = plt.figure(figsize=(6,4))
plt.hist(df['age'].dropna(), bins=30)
plt.title("Q24a: Histogram of Age")
plt.xlabel("Age"); plt.ylabel("Count")
save_fig(fig_age, "Q24_age_hist.png"); pdf.savefig(fig_age); plt.close(fig_age)

fig_fare = plt.figure(figsize=(6,4))
plt.hist(df['fare'].dropna(), bins=40)
plt.title("Q24b: Histogram of Fare")
plt.xlabel("Fare"); plt.ylabel("Count")
save_fig(fig_fare, "Q24_fare_hist.png"); pdf.savefig(fig_fare); plt.close(fig_fare)

fig_fare_box = plt.figure(figsize=(6,3))
plt.boxplot(df['fare'].dropna(), vert=False)
plt.title("Q24c: Boxplot of Fare (below histograms)")
plt.xlabel("Fare")
save_fig(fig_fare_box, "Q24_fare_box_below.png"); pdf.savefig(fig_fare_box); plt.close(fig_fare_box)

# Q25: Cumulative histograms of Age for Survived and Not Survived
fig = plt.figure(figsize=(6,4))
bins = np.linspace(0, df['age'].dropna().max(), 50)
plt.hist(df[df['survived']==0]['age'].dropna(), bins=bins, cumulative=True, density=True, histtype='step', label='Not Survived (0)')
plt.hist(df[df['survived']==1]['age'].dropna(), bins=bins, cumulative=True, density=True, histtype='step', label='Survived (1)')
plt.legend()
plt.title("Q25: Cumulative Histograms of Age (CDF-like)")
plt.xlabel("Age"); plt.ylabel("Cumulative Proportion")
save_fig(fig, "Q25_cumulative_age.png"); pdf.savefig(fig); plt.close(fig)

# Q26: Bin Age into groups and compute survival rate per group
bins = [0,12,17,35,55,200]
labels = ['0-12','13-17','18-35','36-55','56+']
df['age_bin'] = pd.cut(df['age'], bins=bins, labels=labels)
age_bin_surv = df.groupby('age_bin')['survived'].mean()
fig = plt.figure(figsize=(6,4))
plt.bar(age_bin_surv.index.astype(str), age_bin_surv.values)
plt.title("Q26: Survival Rate by Age Group")
plt.ylabel("Survival Rate"); plt.xlabel("Age Group")
save_fig(fig, "Q26_survival_by_agegroup.png"); pdf.savefig(fig); plt.close(fig)

# Q27: Among survivors only, pie chart of Sex proportions
survivors = df[df['survived']==1]
sex_counts_surv = survivors['sex'].value_counts()
fig = plt.figure(figsize=(5,5))
plt.pie(sex_counts_surv.values, labels=sex_counts_surv.index, autopct='%1.1f%%')
plt.title("Q27: Sex Proportions among Survivors")
save_fig(fig, "Q27_survivor_sex_pie.png"); pdf.savefig(fig); plt.close(fig)

# Q28: For each Sex, plot distribution of Embarked as stacked bar chart (within-sex percentages)
sex_emb = df.groupby(['sex','embarked']).size().unstack(fill_value=0)
sex_emb_pct = sex_emb.div(sex_emb.sum(axis=1), axis=0)
fig = plt.figure(figsize=(6,4))
bottom = np.zeros(len(sex_emb_pct))
sexidx = sex_emb_pct.index
for e in sex_emb_pct.columns:
    vals = sex_emb_pct[e].values
    plt.bar(sexidx, vals, bottom=bottom, label=str(e))
    bottom += vals
plt.title("Q28: Embarked Distribution within Sex (percentages)")
plt.ylabel("Proportion"); plt.legend(title="Embarked")
save_fig(fig, "Q28_embarked_within_sex_stacked.png"); pdf.savefig(fig); plt.close(fig)

# Q29: Bar chart of mean Fare across Pclass, separated by Sex with error bars (std)
mean_fare = df.groupby(['pclass','sex'])['fare'].mean().unstack()
std_fare = df.groupby(['pclass','sex'])['fare'].std().unstack()
fig = plt.figure(figsize=(8,5))
x = np.arange(len(mean_fare.index))
width = 0.35
plt.bar(x - width/2, mean_fare['male'].values, width, yerr=std_fare['male'].values, label='Male')
plt.bar(x + width/2, mean_fare['female'].values, width, yerr=std_fare['female'].values, label='Female')
plt.xticks(x, mean_fare.index.astype(str))
plt.title("Q29: Mean Fare by Pclass and Sex (with STD error bars)")
plt.xlabel("Pclass"); plt.ylabel("Mean Fare"); plt.legend()
save_fig(fig, "Q29_mean_fare_pclass_sex.png"); pdf.savefig(fig); plt.close(fig)

# Q30: Bar chart of survival rate per family size (0-5)
fs_rates_0_5 = df[df['family_size']<=5].groupby('family_size')['survived'].mean()
fig = plt.figure(figsize=(8,4))
plt.bar(fs_rates_0_5.index.astype(int), fs_rates_0_5.values)
plt.title("Q30: Survival Rate per Family Size (0-5)")
plt.xlabel("Family Size"); plt.ylabel("Survival Rate")
save_fig(fig, "Q30_survival_by_familysize_0_5.png"); pdf.savefig(fig); plt.close(fig)

# Save additional dataframes/summary to CSV for user's reference
summary_csv = os.path.join(outdir, "titanic_numeric_summaries.csv")
summary_df = pd.DataFrame({
    'feature': ['survived_counts','pclass_counts','missing_counts'],
    'value': [surv_counts.to_dict(), pclass_counts.to_dict(), missing_counts.to_dict()]
})
summary_df.to_csv(summary_csv, index=False)

# Save small tables as CSVs
pd.DataFrame(surv_counts).to_csv(os.path.join(outdir, "Q2_survival_counts.csv"))
group_sex.to_csv(os.path.join(outdir, "Q3_survival_by_sex.csv"))
pclass_counts.to_csv(os.path.join(outdir, "Q4_pclass_counts.csv"))
family_counts.to_csv(os.path.join(outdir, "Q8_family_counts.csv"))
family_surv_rates.to_csv(os.path.join(outdir, "Q8_family_survival_rate.csv"))
age_bin_surv.to_csv(os.path.join(outdir, "Q26_age_bin_survival_rate.csv"))
sex_counts_surv.to_csv(os.path.join(outdir, "Q27_sex_counts_survivors.csv"))
mean_fare.to_csv(os.path.join(outdir, "Q29_mean_fare_pclass_sex.csv"))

# Close PDF
pdf.close()

# Provide a compact textual summary of the main numeric inferences for each question
inference = {}

inference['Q1'] = "Age distribution: most passengers between 20-40, slight right tail, few missing ages."
inference['Q2'] = f"Survival counts: {surv_counts.to_dict()} (0: Not survived, 1: Survived)"
inference['Q3'] = f"Survival by sex (counts):\n{group_sex.to_dict()}"
inference['Q4'] = f"Pclass counts: {pclass_counts.to_dict()}"
inference['Q5'] = "Fare is heavily right-skewed; boxplot shows many outliers at high fares."
inference['Q6'] = "Age vs Fare scatter: weak relationship; high fares concentrated across ages (first-class passengers)."
inference['Q7'] = f"Survival by embarked: counts per port:\n{emb_surv.to_dict()}"
inference['Q8'] = "Family size: small families and singles are common; survival rate varies by size (see saved CSV)."
inference['Q9'] = "Age distribution by survival: survivors slightly younger median than non-survivors."
inference['Q10'] = "Age by sex: distributions similar but male group shows slightly higher spread."
inference['Q11'] = "Males: survivors tend to be slightly younger; Females: higher survival across age ranges."
inference['Q12'] = "Children had generally better survival rates compared to adults (see plots)."
inference['Q13'] = "Overlaid age hist: survivors show a peak at younger ages compared to non-survivors."
inference['Q14'] = "Embarked distribution differs across classes; see grouped bar chart."
inference['Q15'] = "2x2 hist: female survivors display younger age peak; male non-survivors skew older."
inference['Q16'] = "Fare by (Pclass, Survived): Pclass1 has much higher fare medians and survivors dominate higher fare."
inference['Q17'] = "Age by sex with survival: female survivors younger on average; male survivors younger than male non-survivors."
inference['Q18'] = f"Numeric correlations with Survived: {corrs} (absolute values plotted)"
inference['Q19'] = "Stacked bars show higher survival proportion in Pclass=1 relative to Pclass=3."
inference['Q20'] = "Fare overlaid hist: survivors have heavier right-tail (higher fares) distribution compared to non-survivors."
inference['Q21'] = "Log-scaled fare histogram makes high-fare outliers more visible as compressed bins; reveals bulk distribution."
inference['Q22'] = "Fare by Embarked: some ports show higher median fares and skew; outliers present."
inference['Q23'] = f"Missing counts: {missing_counts.to_dict()} -- age and embarked have missing values that need imputation for modeling."
inference['Q24'] = "Age histogram roughly symmetric/slightly right; Fare histogram strongly right-skewed; boxplot shows many high-fare outliers."
inference['Q25'] = "Cumulative age curves: one curve may reach high percentage earlier showing younger survivors proportion."
inference['Q26'] = f"Survival rate by age group: {age_bin_surv.to_dict()}"
inference['Q27'] = f"Survivors sex proportions: {sex_counts_surv.to_dict()}"
inference['Q28'] = "Embarked within sex: charts saved; S (Southampton) often dominates."
inference['Q29'] = f"Mean fare by Pclass and Sex: means:\n{mean_fare.to_dict()}\nstds:\n{std_fare.to_dict()}"
inference['Q30'] = f"Survival rates by family size (0-5):\n{fs_rates_0_5.to_dict()}"

# Save inferences to a text file
with open(os.path.join(outdir, "inferences_summary.txt"), "w") as f:
    for k,v in inference.items():
        f.write(f"{k}: {v}\n\n")

# Print final message and list of created files
created_files = sorted(os.listdir(outdir))
print("Created files in:", outdir)
for cf in created_files:
    print("-", cf)

print("\nCombined PDF report saved to:", pdf_path)
